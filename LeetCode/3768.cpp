class Solution {
    template<typename T> struct SegmentTree {
    T neutral = 0; // CHANGE (neutral element)
    int n;
    vector<T> tree;

    SegmentTree (vector<T> vec) : n((int)vec.size()), tree(2*n) { // n is a power of 2
        for (int i=0; i<n; ++i) tree[n+i] = vec[i];
        for (int i=n-1; i>=1; --i) tree[i] = merge(tree[i*2], tree[i*2+1]);
    }

	T query(int l, int r) { return query(1, 0, n-1, l, r); } // l/r is 0-indexed
	void update(int pos, T v) { update(1, 0, n-1, pos, v); } // pos is 0-indexed

	T query(int pos, int node_l, int node_r, int query_l, int query_r) { // query 0-indexed

    	if (node_r <= query_r && node_l >= query_l) return tree[pos];
    	if (node_l > query_r || node_r < query_l) return neutral;

    	int max_l = (node_l + node_r) >> 1;
    	T q1 = query(pos<<1, node_l, max_l, query_l, query_r);
    	T q2 = query((pos<<1)+1, max_l+1, node_r, query_l, query_r);
    	return merge(q1, q2); // operation
    }

    void update(int pos, int node_l, int node_r, int change_pos, T v) {
        if (change_pos == node_l && change_pos == node_r) {
            tree[pos] += v; return;
        }

        if (change_pos > node_r || change_pos < node_l) return;

        int max_l = (node_l + node_r) >> 1;
        update(pos<<1, node_l, max_l, change_pos, v);
        update((pos<<1)+1, max_l+1, node_r, change_pos, v);
        tree[pos] = merge(tree[pos<<1], tree[(pos<<1)+1]); // operation
    }

    T merge(T a, T b) { // COMPLETE (function)
        return a + b;
    }
};
public:
    long long minInversionCount(vector<int>& a, int k) {
        int n = (int)a.size();

        vector b(a);
        sort(b.begin(), b.end());
    	b.erase(unique(b.begin(), b.end()), b.end());

        map<int,int> pos;
        for (int i=0; i<b.size(); ++i) pos[b[i]] = i;

        vector<int> base(n);
        while (__builtin_popcount(base.size()) != 1) base.push_back(0);
        SegmentTree sgt(base);

        long long cur = 0;
        {
            SegmentTree sgt2(base);
            vector<pair<int,int>> o(k);
            for (int i=0; i<k; ++i) o[i] = {a[i], i};
            sort(o.begin(), o.end());
            for (auto [v, p]: o) {
                cur += sgt2.query(p, k);
                sgt2.update(p, 1);
                sgt.update(pos[v], 1);
            }
        }

        long long ans = cur;
        for (int i=k; i<n; ++i) {
            if (pos[a[i-k]] != 0) cur -= sgt.query(0, pos[a[i-k]] - 1);
            sgt.update(pos[a[i-k]], -1);

            if (pos[a[i]] != n-1) cur += sgt.query(pos[a[i]] + 1, n);

            ans = min(ans, cur);
            sgt.update(pos[a[i]], 1);
        }

        return ans;
    }
};
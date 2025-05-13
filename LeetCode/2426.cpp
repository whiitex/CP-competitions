class Solution {
    template<typename T> struct SegmentTree {
        int n;
        vector<T> tree, lazy;

        SegmentTree (vector<T> vec) : n((int)vec.size()), tree(2*n), lazy(2*n, 0)  { // n is a power of 2
            for (int i=0; i<n; ++i) tree[n+i] = vec[i];
            for (int i=n-1; i>=1; --i) tree[i] = tree[i*2] + tree[i*2+1];
        }

        T query(int pos, int node_l, int node_r, int query_l, int query_r) {
            push_lazy(pos, node_l, node_r);

            if (node_r <= query_r && node_l >= query_l) return tree[pos];
            if (node_l > query_r || node_r < query_l) return 0; // neutral element

            int max_l = (node_l + node_r) >> 1;
            T q1 = query(pos<<1, node_l, max_l, query_l, query_r);
            T q2 = query((pos<<1)+1, max_l+1, node_r, query_l, query_r);
            return q1 + q2; // operation
        }

        void update_range(int pos, int node_l, int node_r, int change_l, int change_r, int v) { // change_l/r is 0-indexed
            push_lazy(pos, node_l, node_r);

            if (node_r <= change_r && node_l >= change_l) {
                tree[pos] += (node_r - node_l + 1) * v; // lazy operation (range update)
                lazy[pos] += v; // lazy update
                push_lazy(pos, node_l, node_r);
                return;
            }

            if (node_l > change_r or node_r < change_l) return;

            int max_l = (node_l + node_r) >> 1;
            update_range(pos<<1, node_l, max_l, change_l, change_r, v);
            update_range((pos<<1)+1, max_l+1, node_r, change_l, change_r, v);
            tree[pos] = tree[pos<<1] + tree[(pos<<1)+1]; // operation
        }


        void push_lazy(int pos, int node_l, int node_r) {
            if (lazy[pos] and pos < n) {
                tree[pos*2] += (node_r - node_l + 1) / 2 * lazy[pos]; // lazy operation (range update)
                tree[pos*2 + 1] += (node_r - node_l + 1) / 2 * lazy[pos]; // lazy operation (range update)

                if (pos*2 < n) {
                    lazy[pos*2] += lazy[pos]; // lazy below update
                    lazy[pos*2+1] += lazy[pos]; // lazy below update
                }
            }  lazy[pos] = 0; // neutral element (on lazy)
        }
    };

    const int MXN = 1 << 17;

public:
    long long numberOfPairs(vector<int>& a, vector<int>& b, int d) {
        int n = a.size();
        vector<int> c(n); for (int i=0; i<n; ++i) c[i] = a[i] - b[i];
        for (int &i: c) i += 3e4;

        vector<long long> base(MXN, 0);
        SegmentTree sgt(base);

        long long ans = 0;
        for (int i=n-1; i>=0; --i) {
            if (i < n-1) ans += sgt.query(1, 0, MXN-1, c[i]-d, c[i]-d);
            sgt.update_range(1, 0, MXN-1, 0, c[i], 1);
        }
        
        return ans;
    }
};
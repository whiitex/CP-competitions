class Solution {
	template<typename T> struct SegmentTree {
		T neutral = 0; // CHANGE (neutral element)
		int n;
		vector<T> tree;

		SegmentTree (vector<T> vec) : n((int)vec.size()), tree(2*n) { // n is a power of 2
			for (int i=0; i<n; ++i) tree[n+i] = vec[i];
			for (int i=n-1; i>=1; --i) tree[i] = merge(tree[i*2], tree[i*2+1]);
		}

		T query(int pos, int node_l, int node_r, int query_l, int query_r) { // query 0-indexed

			if (node_r <= query_r && node_l >= query_l) return tree[pos];
			if (node_l > query_r || node_r < query_l) return neutral;

			int max_l = (node_l + node_r) >> 1;
			T q1 = query(pos<<1, node_l, max_l, query_l, query_r);
			T q2 = query((pos<<1)+1, max_l+1, node_r, query_l, query_r);
			return merge(q1, q2); // operation
		}

		void update(int pos, int node_l, int node_r, int change_pos, int v) {
			if (change_pos == node_l && change_pos == node_r) {
				tree[pos] = v; return;
			}

			if (change_pos > node_r || change_pos < node_l) return;

			int max_l = (node_l + node_r) >> 1;
			update(pos<<1, node_l, max_l, change_pos, v);
			update((pos<<1)+1, max_l+1, node_r, change_pos, v);
			tree[pos] = merge(tree[pos<<1], tree[(pos<<1)+1]); // operation
		}

		T merge(T a, T b) { return a + b; }
	};

public:
	vector<int> longestSpecialPath(vector<vector<int>>& e, vector<int>& a) {
		vector adj(a.size()+1, vector<array<int,2>>());
		for (auto v: e) {
			int q = v[0], w = v[1], r = v[2];
			adj[q].push_back({w, r});
			adj[w].push_back({q, r});
		}

		int N = 1<<16;
		vector<int> base(N);
		SegmentTree sgt(base);
		vector<set<int>> values(6e4);
		set<int> blockset = {-9};
		vector<int> block(N);

		int longest = -1, nodes;
		auto dfs = [&] (auto f, int u, int par, int len, int depth) -> void {

			values[a[u]].insert(-depth);
			auto it = values[a[u]].upper_bound(-depth);
			if (it != values[a[u]].end()) {
				++block[-*it];
				if (block[-*it] == 1) blockset.insert(*it);
			}

			sgt.update(1, 0, N-1, depth, len);

			int pos = -*blockset.upper_bound(-depth); if (pos == 9) ++pos;
            pos = -*blockset.upper_bound(-pos); ++pos;
    		int LEN = sgt.query(1, 0, N-1, pos+1, N-1);

			if (LEN == longest) {
				nodes = min(nodes, depth - pos + 1);
			} else if (LEN > longest) {
				longest = LEN;
				nodes = depth - pos + 1;
			}

			for (auto [v, w]: adj[u]) if (v != par) f(f, v, u, w, depth+1);

			sgt.update(1, 0, N-1, depth, 0);
			values[a[u]].erase(-depth);
			if (it != values[a[u]].end()) {
				--block[-*it];
				if (block[-*it] == 0) blockset.erase(*it);
			}

		};

		dfs(dfs, 0, -1, 0, 10);
		return {longest, nodes};
	}
};
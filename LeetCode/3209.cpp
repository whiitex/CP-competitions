class Solution {
public:
	typedef long long ll;
	template <typename T> struct SegmentTree {
		vector<T> tree;

		SegmentTree(vector<T> vec, int n) { // n is a power of 2
			tree.resize(2 * n);

			for (int i = 0; i < n; ++i)
				tree[n + i] = vec[i];

			for (int i = n - 1; i >= 1; --i)
				tree[i] = tree[i * 2] & tree[i * 2 + 1];
		}

		T query(int pos, int node_l, int node_r, int query_l, int query_r) {

			if (node_r <= query_r && node_l >= query_l)
				return tree[pos];

			if (node_l > query_r || node_r < query_l)
				return ((1 << 30) - 1);

			int max_l = (node_l + node_r) >> 1;
			return query(pos << 1, node_l, max_l, query_l, query_r) &
				   query((pos << 1) + 1, max_l + 1, node_r, query_l, query_r);
		}
	};

	ll countSubarrays(vector<int>& vec, int k) {
		ll N = vec.size(), ans = 0;

		vector<ll> add(N, 0);
		for (int i = 0; i < N;) {
			int j = i + 1;
			while (j < N and (vec[j] & k) == k)
				++j;

			for (int p = i; p < j; ++p)
				add[p] = j - p;

			i = j;
		}

		while (__builtin_popcount(vec.size()) != 1)
			vec.push_back((1 << 30) - 1);
		ll n = vec.size();

		SegmentTree<int> segtree(vec, n);

		for (int i = 0; i < N; ++i) {
			ll l = i, r = N-1;
			while (vec[i] >= k and l < r) {
				ll mid = (l + r) >> 1;
				ll subarr = segtree.query(1, 0, n - 1, i, mid);
				if (subarr <= k)
					r = mid;
				else
					l = mid+1;
			}

			if (segtree.query(1, 0, n - 1, i, l) == k)
				ans += add[l];
		}
		return ans;
	}
};
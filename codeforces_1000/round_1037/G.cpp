#pragma GCC optimize/("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;

#define pb push_back

const int INF = 8e18;

template<typename T> struct SegmentTree {
	T neutral = INF; // CHANGE (neutral element)
	int n;
	vector<T> tree;

	SegmentTree (vector<T> vec) : n((int)vec.size()), tree(2*n) { // n is a power of 2
		for (int i=0; i<n; ++i) tree[n+i] = vec[i];
		for (int i=n-1; i>=1; --i) tree[i] = merge(tree[i*2], tree[i*2+1]);
	}

	T query(int l, int r) { return query(1, 0, n-1, l, r); } // l/r is 0-indexed

	T query(int pos, int node_l, int node_r, int query_l, int query_r) { // query 0-indexed

		if (node_r <= query_r && node_l >= query_l) return tree[pos];
		if (node_l > query_r || node_r < query_l) return neutral;

		int max_l = (node_l + node_r) >> 1;
		T q1 = query(pos<<1, node_l, max_l, query_l, query_r);
		T q2 = query((pos<<1)+1, max_l+1, node_r, query_l, query_r);
		return merge(q1, q2); // operation
	}

	T merge(T a, T b) { // COMPLETE (function)
		return min(a, b);
	}
};

void solve() {
	int n; cin >> n;
	vi a(n); for (int &i: a) cin >> i;

	while (__builtin_popcount(a.size()) != 1) a.pb(INF);
	SegmentTree sgt(a);

	int ans = 0;
	set<int> unique(a.begin(), a.end());
	for (int x: unique) {

		vi last(2*n+2, -INF);
		for (int i=0, c=0; i<n; ++i) {
			a[i] >= x ? ++c : --c;
			last[c + n] = i;
		}

		for (int i=0, c=0; i<n; ++i) {
			if (last[c + n] >= i) ans = max(ans, x - sgt.query(i, last[c + n]));
			if (last[c+1 + n] >= i) ans = max(ans, x - sgt.query(i, last[c+1 + n]));

			a[i] >= x ? ++c : --c;
		}
	}

	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
}

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;

#define pb push_back

const int INF = 8e18;

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
			tree[pos] = v; return;
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

void solve() {
    int n, k; cin >> n >> k;
    vi a(n); for (int &i: a) cin >> i;

	if (k <= 2) { cout << "YES\n"; return; }

	for (int i=0; i*2<n; ++i) {
		if (a[i] != a[n-i-1]) break;
		if ((i+1) * 2 >= n) { cout << "YES\n"; return; }
	}

	vi base(n); while (__builtin_popcount(base.size()) != 1) base.pb(0);
	SegmentTree sgt(base);

	vector f(n+1, vi());
	for (int i=0; i<n; ++i) {
		f[a[i]].pb(i);
	}

	int x = 0, cnt = 0;
	while (cnt < k-1) {
		++x;

		cnt += (int)f[x].size();
		if (f[x].empty()) continue;

		int j = (int)f[x].size() - 1;
		int taken = 0;
		for (int i=0; i<=j; ++i) {

			int lx = sgt.query(0, f[x][i]);
			while (j > i and sgt.query(f[x][j], n-1) < lx) --j;

			if (lx == sgt.query(f[x][j], n-1)) {
				taken += (i == j ? 1 : 2);
				sgt.update(f[x][i], 1);
				sgt.update(f[x][j], 1);
				--j;
			}
		}

		if (taken != f[x].size() and cnt < k-1) break;
	}

	if (sgt.query(0, n-1) >= k-1) cout << "YES\n";
	else cout << "NO\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

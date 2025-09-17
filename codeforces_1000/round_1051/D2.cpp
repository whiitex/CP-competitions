// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef __int128_t lll; typedef long double ld;
typedef pair<int,int> pii; typedef pair<ld,ld> pld;
typedef vector<int> vi; typedef vector<pii> vpii;

#define pb push_back
#define st first
#define nd second

const int MXN = 5e5 + 5;
const int MOD = 1e9 + 7;
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
			tree[pos] = (tree[pos] + v) % MOD; return;
		}

		if (change_pos > node_r || change_pos < node_l) return;

		int max_l = (node_l + node_r) >> 1;
		update(pos<<1, node_l, max_l, change_pos, v);
		update((pos<<1)+1, max_l+1, node_r, change_pos, v);
		tree[pos] = merge(tree[pos<<1], tree[(pos<<1)+1]); // operation
	}

	T merge(T a, T b) { return (a + b) % MOD; }
};


void solve() {
	int n; cin >> n;
	vi a(n); for (int &i: a) cin >> i;

	int N = n+2; while (__builtin_popcount(N) != 1) ++N;
	vector sgtRed(n+2, SegmentTree(vi(N)));
	vector sgtBlu(n+2, SegmentTree(vi(N)));

	sgtRed[n+1].update(n+1, 1);
	sgtBlu[n+1].update(n+1, 1);

	for (int i=n-1; i>=0; --i) {

		int ai = a[i];
		for (int i=0; i<ai; ++i) {
			int add = sgtRed[i].query(ai, n+1);
			sgtBlu[ai].update(i, add);
			sgtRed[i].update(ai, add);
		}
		for (int i=ai; i<=n+1; ++i) {
			int add = sgtBlu[i].query(ai, n+1);
			sgtRed[ai].update(i, add);
			sgtBlu[i].update(ai, add);
		}
	}

	int ans = 0;
	for (int i=0; i<=n+1; ++i) {
		ans = (ans + sgtRed[i].query(0, n+1)) % MOD;
	}
	cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

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

void solve() {
    int n; cin >> n;
	vector adj(n+1, vector<array<int,3>>());
	for (int i=1; i<n; ++i) {
		int u, v, x, y; cin >> u >> v >> x >> y;
		adj[u].pb({v, x, y});
		adj[v].pb({u, y, x});
	}

	vi dim(n+1);
	auto dfs = [&](auto f, int u, int p) -> int {
		int sz = 1;
		for (auto [v, x, y]: adj[u]) if (v != p) {
			sz += f(f, v, u);
		} return dim[u] = sz;
	};	dfs(dfs, 1, -1);

	vi ans(n + 1);
	auto dfs2 = [&] (auto f, int u, int p, int l, int r) -> void {
		for (auto [v, x, y]: adj[u]) if (v != p) {
			// if (v < u) swap(x, y);
			if (x > y) f(f, v, u, l, l + dim[v] - 1), l += dim[v];
			else f(f, v, u, r - dim[v] + 1, r), r -= dim[v];
		}

		ans[u] = l;
	};
	dfs2(dfs2, 1, -1, 1, n);

	for (int i=1; i<=n; ++i) cout << ans[i] << ' '; cout << "\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

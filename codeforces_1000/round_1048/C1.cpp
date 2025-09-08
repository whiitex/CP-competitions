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
    int n, k; cin >> n >> k;
	vector adj(n, vi());
	for (int i=1; i<n; ++i) {
		int p; cin >> p; --p;
		adj[p].pb(i);
	}

	vi level(n+3); int minlev = INF;
	auto dfs = [&] (auto f, int u, int lev) -> void {
		++level[lev];
		if (adj[u].empty()) minlev = min(minlev, lev);
		for (int v: adj[u]) f(f, v, lev + 1);
	}; dfs(dfs, 0, 1);

	int ans = 1;
	k = max(k, n - k);
	vector<bool> dp(n+1); dp[0] = 1;

	for (int lev=1, tot = 0; lev<=minlev; ++lev) {
		int cnt = level[lev];
		tot += cnt;

		if (cnt == 1) ans = lev;
		else {
			for (int i=n; i>=0; --i) if (dp[i]) {
				int a = i, b = tot - i;
				if (a <= k and b <= n-k) ans = lev;
				if (a <= n-k and b <= k) ans = lev;

				a = i + cnt; b = tot - a;
				if (a <= k and b <= n-k) ans = lev;
				if (a <= n-k and b <= k) ans = lev;

				dp[i + cnt] = 1;
			}
		}

		if (ans != lev) break;
	}

	cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

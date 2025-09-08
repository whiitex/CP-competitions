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

const int MXN = 2e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 8e18;

bitset<MXN> dp, ones;

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

	for (int i=0; i<=k; ++i) ones.set(i);

	dp.set(0);
	int pl = 0;
	for (int lev=1, tot = 0; lev<=minlev; ++lev) {
		int cnt = level[lev];
		tot += cnt;

		dp |= (dp << cnt);

		int l = max(0ll, tot-n+k);
		for (int i=pl+1; i<=l; ++i) ones.reset(k+1-i);
		pl = l;

		auto mask = (dp >> l) & ones;

		if (mask.any()) ans = lev;
		else break;
	}

	for (int i=0; i<=n+1; ++i) dp.reset(i), ones.reset(i);
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
}

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

#define pb push_back

void solve() {
	int n, q; cin >> n >> q;
	vi a(n); for (int &i: a) cin >> i;
	vector adj(n, vpii());
	int tot = 0;
	map<pii, int> edges;
	for (int i=1; i<n; ++i) {
		int u, v, c; cin >> u >> v >> c; --u, --v;
		adj[u].pb({v, c}); adj[v].pb({u, c});
		tot += c;
		edges[{u, v}] = edges[{v, u}] = c;
	}

	vector store(n, map<int,int>());
	vi par(n, -1);
	auto dfs = [&] (auto f, int u, int p) -> void {
		for (auto [v, c]: adj[u]) if (v != p) {
			par[v] = u;
			store[u][a[v]] += c;
			f(f, v, u);
		}
	}; dfs(dfs, 0, -1);

	int rem = 0;
	for (int u=0; u<n; ++u) rem += store[u][a[u]];

	while (q--) {
		int v, x; cin >> v >> x; --v;

		int prev = store[v].contains(a[v]) ? store[v][a[v]] : 0;
		if (v and a[par[v]] == a[v]) prev += edges[{v, par[v]}];

		int now = store[v].contains(x) ? store[v][x] : 0;
		if (v and a[par[v]] == x) now += edges[{v, par[v]}];

		// update
		if (v) {
			store[par[v]][a[v]] -= edges[{v, par[v]}];
			if (store[par[v]][a[v]] == 0) store[par[v]].erase(a[v]);
		}

		if (v) store[par[v]][x] += edges[{v, par[v]}];
		a[v] = x;

		rem = rem - prev + now;

		cout << tot - rem << '\n';
	}

}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
}

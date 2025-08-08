#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;

#define pb push_back


void solve() {
    int n, k; cin >> n >> k;
	vi w(n+1); for (int i=1; i<=n; ++i) cin >> w[i];
	vi col(n+1); for (int i=1; i<=n; ++i) cin >> col[i];
	vector adj(n+1, vi());
	for (int i=1; i<n; ++i) {
		int u, v; cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}


	vi iscutie(n+1);
	int cost = 0;
	auto dfs = [&](auto f, int v, int p) -> set<int>* {
		auto* big = new set<int>();

		for (int u: adj[v]) if (u != p) {
			set<int>* small = f(f, u, v);

			if (small->size() > big->size()) swap(small, big);
			for (int c: *small) {
				if (big->contains(c)) {
					if (c != col[v] and !iscutie[v]) {
						if (col[v] != 0) {
							iscutie[v] = true;
							cost += w[v];
						} else col[v] = c;
					}
				}
				big->insert(c);
			}
		}

		if (col[v] != 0) big->insert(col[v]);
		return big;
	};
	dfs(dfs, 1, -1);

	if (col[1] == 0) col[1] = 1;
	auto dfs2 = [&] (auto f, int u, int p) -> void {
		if (col[u] == 0) col[u] = col[p];
		for (int v: adj[u]) if (v != p) f(f, v, u);
	};
	dfs2(dfs2, 1, -1);

	cout << cost << '\n';
	for (int i=1; i<=n; ++i) cout << col[i] << ' ';
	cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

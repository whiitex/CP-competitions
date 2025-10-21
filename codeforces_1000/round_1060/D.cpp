// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

#define pb push_back
#define st first
#define nd second

constexpr int MXN = 5e5 + 5;
constexpr int MOD = 1e9 + 7;
constexpr int INF = 8e18;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int uniform_distr(int a, int b) {
	return uniform_int_distribution<int>(a, b)(rng);
}

void solve() {
	int n; cin >> n;
	vector adj(n, set<int>());
	for (int i=1; i<n; ++i) {
		int u, v; cin >> u >> v; --u; --v;
		adj[u].insert(v); adj[v].insert(u);
	}

	vi type(n), par(n, -1); // 0:even, 1:odd
	auto dfs = [&] (auto f, int u, int p, int t=0) -> void {
		type[u] = t;
		for (int v: adj[u]) if (v != p) {
			par[v] = u;
			f(f, v, u, t^1);
		}
	}; dfs(dfs, 0, -1);

	set<int> path{0, n-1};
	vi srtpath;
	auto dfs2 = [&] (auto f, int u, int p) -> int {
		if (u == n-1) return 1;
		for (int v: adj[u]) if (v != p) {
			if (f(f, v, u)) {
				path.insert(u);
				srtpath.pb(u);
				return 1;
			}
		}
		return 0;
	}; dfs2(dfs2, 0, -1);

	reverse(srtpath.begin(), srtpath.end());

	set<int> leaf[2];
	for (int i=0; i<n; ++i) {
		if (adj[i].size() == 1 and !path.contains(i)) {
			leaf[type[i]].insert(i);
		}
	}

	vpii ans;

	int now = 0, cnt = 0, targ = n - (int)path.size();
	while (cnt < targ) {
		if (!leaf[now ^ 1].empty()) {
			int l = *leaf[now ^ 1].begin();
			leaf[now ^ 1].erase(l);

			ans.pb({2, l + 1});

			adj[par[l]].erase(l);
			if (adj[par[l]].size() == 1 and !path.contains(par[l])) {
				leaf[type[par[l]]].insert(par[l]);
			}

			++cnt;
		}

		ans.pb({1, 0});
		now ^= 1;
	}

	if (now == 0) {
		ans.pb({1, 0});
	}

	for (int x: srtpath) {
		ans.pb({2, x + 1});
		ans.pb({1, 0});
	}

	cout << ans.size() << '\n';
	for (auto [t, x]: ans) {
		if (t == 1) cout << "1\n";
		else cout << "2 " << x << '\n';
	}
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

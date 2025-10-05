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

constexpr int MXN = 5e5 + 5;
constexpr int MOD = 1e9 + 7;
constexpr int INF = 8e18;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int uniform_distr(int a, int b) {
	return uniform_int_distribution<int>(a, b)(rng);
}

int ask(int u, int v) {
	cout << u << ' ' << v;
	cout << endl; cout.flush();
	int x; cin >> x; return x;
}

void solve() {
    int n; cin >> n;

	map<pii, bool> vis;
	for (int i=1; i<=n; ++i) vis[{i, i}] = 1;

	vector<pii> to_ask;
	int last = 1;
	while (to_ask.size() != n * (n-1) / 2) {

		int done = 0;
		for (int rep=0; rep<n and !done; ++rep) {
			int j = (last + rep) % n;
			if (j == 0) j = n;

			if (!vis[{last, j}]) {
				vis[{last, j}] = vis[{j, last}] = 1;
				to_ask.pb({last, j});
				last = j;
				done = 1;
			}
		}

		if (!done) ++last;
		if (last > n) last = 1;
	}

	for (auto [u, v]: to_ask) {
		if (ask(u, v)) return;
	}
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

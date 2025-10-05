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

void solve() {
	int n, k; cin >> n >> k;

	if (n * n - k == 1) { cout << "No\n"; return; }

	vector<string> g(n, string(n, 'D'));
	if (k != n * n) {
		k = n * n - k - 2;
		g[0][0] = 'R'; g[0][1] = 'L';
		for (int i=0; i<n; ++i) {
			if (k == 0) break;
			for (int j= i == 0 ? 2 : 0; j<n; ++j) {
				if (k == 0) break;
				g[i][j] = i == 0 ? 'L' : 'U';
				--k;
			}
		}
	}

	cout << "Yes\n";
	for (string &s: g) cout << s << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

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
	int n, m, k; cin >> n >> m >> k;

	map<int,int> col;
	for (int i=0; i<k; ++i) {
		int x, y; cin >> x >> y;
		++col[y];
	}

	if (m == 1) { cout << "Yuyu\n"; return; }

	bool mimo = 0;
	if (n == 1) mimo = col[2] & 1;
	else {
		for (auto [c, tok]: col) if (c > 1) {
			mimo = tok & 1;
			if (mimo) break;
		}
	}

	cout << (mimo ? "Mimo" : "Yuyu") << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

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
	vector g(2, vi(n));
	for (int r=0; r<2; r++) {
		for (int &i: g[r]) cin >> i;
	}

	vector c(2, vpii(n)); // mxl, mnr
	c[0][0] =  {g[0][0], g[0][0]};
	for (int i=1; i<n; ++i) {
		c[0][i] = {min(c[0][i-1].st, g[0][i]),
			max(c[0][i-1].nd, g[0][i])};
	}
	c[1][n-1] = {g[1][n-1], g[1][n-1]};
	for (int i=n-2; i>=0; --i) {
		c[1][i] = {min(c[1][i+1].st, g[1][i]),
			max(c[1][i+1].nd, g[1][i])};
	}

	vi p(2*n+2, 2*n+1);
	for (int i=0; i<n; ++i) {
		int l = min(c[0][i].st, c[1][i].st);
		int r = max(c[0][i].nd, c[1][i].nd);

		p[l] = min(p[l], r);
	}

	int ans = 0;
	for (int i=2*n; i>=1; --i) {
		p[i] = min(p[i], p[i+1]);
		ans += 2*n+1 - p[i];
	}

	cout << ans << '\n';
}

void solve2() { }

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s = "f"; // cin >> s;
	int t = 1; cin >> t;
	while (t--) s[0] == 'f' ? solve() : solve2();
}
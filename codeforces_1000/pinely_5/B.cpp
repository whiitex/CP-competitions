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
	vector<string> g(n);
	for (string &s: g) cin >> s;

	int tot = 0;
	for (string &s: g) for (char c: s) tot += c == '#';

	if (n <= 2) {
		cout << "YES\n";
		return;
	}

	for (int i=0; i<n-1; ++i) for (int j=0; j<n-1; ++j) {
		int cnt = 0;
		cnt += g[i][j] == '#';
		cnt += g[i+1][j] == '#';
		cnt += g[i][j+1] == '#';
		cnt += g[i+1][j+1] == '#';
		if (cnt == tot) {
			cout << "YES\n";
			return;
		}
	}

	auto check = [&] (int x, int y, int dx, int dy) -> int {
		int cnt = 0;
		while (x < n and x >= 0 and y < n and y >= 0) {
			cnt += g[x][y] == '#';
			x += dx; y += dy;
		}
		return cnt;
	};

	for (int x=0; x<n-1; ++x) {
		int cnt = check(x, 0, -1, 1) + check(x+1, 0, -1, 1);
		if (cnt == tot) {
			cout << "YES\n";
			return;
		}
	}
	for (int y=0; y<n-1; ++y) {
		int cnt = check(n-1, y, -1, 1) + check(n-1, y+1, -1, 1);
		if (cnt == tot) {
			cout << "YES\n";
			return;
		}
	}

	for (string &s: g) reverse(s.begin(), s.end());

	for (int x=0; x<n-1; ++x) {
		int cnt = check(x, 0, -1, 1) + check(x+1, 0, -1, 1);
		if (cnt == tot) {
			cout << "YES\n";
			return;
		}
	}
	for (int y=0; y<n-1; ++y) {
		int cnt = check(n-1, y, -1, 1) + check(n-1, y+1, -1, 1);
		if (cnt == tot) {
			cout << "YES\n";
			return;
		}
	}

	cout << "NO\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

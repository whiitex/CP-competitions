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
	string s; cin >> s;

	int n = (int)s.size();

	int sss = 0;
	for (char c: s) sss += c == 's';

	if (sss == 0) { cout << (n + 2) / 2 << '\n'; return; }

	int l = -1, ans = 0;
	for (int i=0; i<n; ++i)  {
		if (s[i] == 's') l = i;
		else {
			int j = i;
			while (j + 1 < n and s[j + 1] == 'u') ++j;

			int cnt = j - i + 1;
			if (l != -1) --cnt;
			if (j != n - 1) --cnt;

			ans += (cnt + 2) / 2;

			i = j;
		}
	}

	if (ans + sss < 2) ++ans;
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
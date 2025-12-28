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
    vi a(n); for (int &i: a) cin >> i;

	int allneg = 1, allpos = 1;
	for (int i: a) {
		if (i < 0) allpos = 0;
		if (i > 0) allneg = 0;
	}

	if (allpos) {
		int tot = 0;
		for (int i=0; i<n-1; ++i) tot += a[i];
		cout << tot << '\n';
		return;
	}
	if (allneg) {
		int tot = 0;
		for (int i=1; i<n; ++i) tot -= a[i];
		cout << tot << '\n';
		return;
	}

	int ans1 = 0;
	for (int i=1; i<n; ++i) ans1 -= a[i];

	int ans2 = -INF;
	int j = n-1;
	while (j >= 0 and a[j] < 0) --j;

	if (j != -1) {
		ans2 = 0;
		for (int i=0; i<j; ++i) ans2 += abs(a[i]);

		int mn = INF, tot = 0;
		for (int i=j; i<n; ++i) {
			tot += abs(a[i]);
			mn = min(mn, abs(a[i]));
		}

		ans2 += tot - mn;
	}

	if (a[0] < 0) ans2 += 2 * a[0];

	cout << max(ans1, ans2) << '\n';
}

void solve2() { }

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s = "f"; // cin >> s;
	int t = 1; cin >> t;
	while (t--) s[0] == 'f' ? solve() : solve2();
}
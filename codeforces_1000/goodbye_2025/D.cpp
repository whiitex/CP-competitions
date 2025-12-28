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
	int n, m; cin >> n >> m;
	vpii a(n);
	for (int i=0; i<n; ++i) {
		cin >> a[i].st;
		a[i].nd = i+1;
	}

	if (m > n/2) { cout << "-1\n"; return; }

	sort(a.begin(), a.end());

	vpii ans;

	if (m == 0) {
		int sm = 0, j = n-2;
		for (; j>=0; --j) {
			sm += a[j].st;
			if (sm >= a[n-1].st) break;
		}

		if (sm < a[n-1].st) { cout << "-1\n"; return; }

		for (int i=0; i<j; ++i) ans.pb({a[i].nd, a[i+1].nd});
		ans.pb({a[n-1].nd, a[j].nd});
		for (int i=j+1; i<n-1; ++i) ans.pb({a[i].nd, a[n-1].nd});

	} else {

		for (int i=0; i<n-2*m; ++i) ans.pb({a[i].nd, a[i+1].nd});
		for (int i=n-2*m; i<n-1; i+=2) ans.pb({a[i+1].nd, a[i].nd});
	}

	cout << ans.size() << '\n';
	for (auto [x,y] : ans) cout << x << ' ' << y << '\n';
}

void solve2() { }

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s = "f"; // cin >> s;
	int t = 1; cin >> t;
	while (t--) s[0] == 'f' ? solve() : solve2();
}
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

	vi p(a); for (int i=1; i<n; ++i) p[i] = max(p[i], p[i-1]);

	for (int i=1; i<n; i+=2) a[i] = p[i];

	int ans = 0;
	for (int i=0; i<n; i+=2) {
		int mn = min(i == 0 ? INF : a[i-1], i==n-1 ? INF : a[i+1]);
		if (mn <= a[i]) ans += a[i] - mn + 1;
	}

	cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

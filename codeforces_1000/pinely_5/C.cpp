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
    int n, x; cin >> n >> x;
    vi a(n); for (int &i: a) cin >> i;

	sort(a.begin(), a.end());

	vi v;
	int ans = 0, r = n-1, tot = 0;
	for (int i=0; i<=r; ++i) {
		if (tot / x != (tot + a[r]) / x) {
			v.pb(a[r]);
			tot += a[r];
			ans += a[r];
			--r; --i;
		} else {
			tot += a[i];
			v.pb(a[i]);
		}
	}

	cout << ans << '\n';
	for (int i: v) cout << i << ' ';
	cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

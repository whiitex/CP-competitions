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
constexpr int MOD = 676767677;
constexpr int INF = 8e18;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int uniform_distr(int a, int b) {
	return uniform_int_distribution<int>(a, b)(rng);
}

void solve() {
    int n; cin >> n;
    vi a(n); for (int &i: a) cin >> i;

	for (int &i: a) --i;

	if (a[0] + a[n-1] > n) { cout << 0 << '\n'; return; }

	// type 0:Left, 1:Right
	auto check = [&] (int x) -> bool {
		vi type(n); type[0] = x;
		for (int i=1; i<n; ++i) {
			if (a[i] == a[i-1]) {
				if (type[i-1] == 0) type[i] = 1;
				else type[i] = 0;
			} else if (a[i] == a[i-1] + 1) {
				if (type[i-1] == 1) return false;
				type[i] = 0;
			} else if (a[i] == a[i-1] - 1) {
				if (type[i-1] == 0) return false;
				type[i] = 1;
			} else return false;
		}

		vpii suff(n+1);
		for (int i=n-1; i>=0; --i) {
			if (type[i] == 0) ++suff[i].nd;
			else ++suff[i].st;
			suff[i].st += suff[i+1].st;
			suff[i].nd += suff[i+1].nd;
		}

		int l = 0;
		vi res(n);
		for (int i=0; i<n; ++i) {
			res[i] = l + suff[i+1].st;
			if (type[i] == 0) ++l;
		}

		for (int i=0; i<n; ++i) if (res[i] != a[i]) return false;

		return true;
	};

	int ans = check(0) + check(1);
	cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

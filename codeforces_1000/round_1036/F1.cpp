#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

#define st first
#define nd second

const int MOD = 998244353;

void solve() {
	int n, m; cin >> n >> m;
	vpii a(m); for (int i=0; i<m; ++i) {
		cin >> a[i].st >> a[i].nd;
	}

	vi dp(n+1); dp[0] = 1;

	vector ok(n+1, vi(n+1, 0)); // pos, len
	for (int x=1; x<=n; ++x) for (int i=0; i<x; ++i) {
		int sz = x - i;
		vector s(x-i+1, true);
		for (auto [p, v]: a) {
			if (p > i and p <= x and v <= sz) {
				int rem = (v + sz - p+i) % sz + 1;
				s[rem] = false;
			}
		}

		int tot = 0, rem = 0;
		for (int j=1; j<=sz; ++j) if (s[j]) {
			++tot;

			if (j > 1 and i-j+2 > 0) rem = (rem + ok[i-j+2][j-1]) % MOD;
		}

		dp[x] = (dp[x] + dp[i] * tot) % MOD;
		dp[x] = (dp[x] - rem + MOD) % MOD;


		if (s[1]) ok[i+1][sz] = (ok[i+1][sz] + dp[i]) % MOD;
	}

	cout << dp[n] << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

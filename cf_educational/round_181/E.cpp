#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;

const int MOD = 998244353;


void solve() {
	int n, x; cin >> n >> x;

	if (n == 1) { cout << x << '\n'; return; }
	if (n == 2) { cout << (x * (x-1) / 2 % MOD) << '\n'; return; }

	int minsum = n * (n+1) / 2;
	int maxsum = x + 1;
	if (minsum - 1 > x) { cout << 0 << '\n'; return; }

	vi dp(maxsum+1, 0); dp[minsum] = 1;
	for (int i=1; i<n; ++i) {
		vi ndp(maxsum+1, 0);
		for (int s=minsum; s<=maxsum; ++s) {
			ndp[s] = (ndp[s] + ndp[s-(n-i)]) % MOD;
			ndp[s] = (ndp[s] + dp[s]) % MOD;
		}

		swap(dp, ndp);
	}

	int ans = 0;
	for (int s=minsum; s<=maxsum; ++s) {
		ans = (ans + (dp[s] * (x+1 - (s-1)))) % MOD;
	}

	cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

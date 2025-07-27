#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
	int n; cin >> n;
	vi a(n); for (int &i: a) cin >> i;

	vi dp(n);
	dp[n-1] = 1;
	dp[n-2] = 2 + (a[n-2] > a[n-1]);

	for (int i=n-3; i>=0; --i) {
		if (a[i+1] > a[i]) {
			dp[i] = dp[i+1] + 1;
		} else {
			if (a[i+2] < a[i+1]) {
				dp[i] = dp[i+1] + (n-i);
			} else {
				dp[i] = dp[i+2] + (n-i-1) + 2;
			}
		}
	}

	int ans = 0;
	for (int i=0; i<n; ++i) ans += dp[i];
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
}

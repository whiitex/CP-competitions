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

const int MXN = 5e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 8e18;



void solve() {
	int n; cin >> n;
	vi a(n); for (int &x : a) cin >> x;

	vector dp(n, vector(n+2, vi(n+2))); // pos, mnblu, mnred
	dp[n-1][n+1][n+1] = 1;
	dp[n-1][n+1][a[n-1]] = 1;

	for (int i=n-2; i>=0; --i) {
		for (int mnblu=0; mnblu<=n+1; ++mnblu) {
			for (int mnred=0; mnred<=n+1; ++mnred) {

				// take
				if (a[i] <= mnblu) {
					if (a[i] <= mnred) {
						int r = min(mnred, a[i]);
						dp[i][mnblu][r] += dp[i+1][mnblu][mnred];
						dp[i][mnblu][r] %= MOD;
					} else if (a[i] > mnred) {
						int b = min(mnblu, a[i]);
						dp[i][b][mnred] += dp[i+1][mnblu][mnred];
						dp[i][b][mnred] %= MOD;
					}
				}

				// dont take
				dp[i][mnblu][mnred] += dp[i+1][mnblu][mnred];
				dp[i][mnblu][mnred] %= MOD;
			}
		}
	}

	int ans = 0;
	for (int mnblu=0; mnblu<=n+1; ++mnblu) {
		for (int mnred=0; mnred<=n+1; ++mnred) {
			ans = (ans + dp[0][mnblu][mnred]) % MOD;
		}
	}

	cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

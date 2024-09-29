#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

const int INF = 1e18;

void solve() {
    int n; cin >> n;
    vi vec(n+1);
    for (int i=1; i<=n; ++i) cin >> vec[i];

    vector dp(n+1, vi(3, INF)); dp[0] = {0,1,1};
    for (int i=1; i<=n; ++i) {
        for (int k: {0,1,2}) {
            dp[i][0] = min(dp[i][0], dp[i-1][k] + 1);
        }

        if (vec[i] == 0) for (int k: {0,1,2}) {
            dp[i][0] = min(dp[i][0], dp[i-1][k]);
        } else if (vec[i] <= 2) {
            dp[i][0] = min(dp[i][0], dp[i-1][1]);
            dp[i][1] = min(dp[i][1], dp[i-1][2] + 1);
            dp[i][1] = min(dp[i][1], dp[i-1][0] + 1);
        } else if (vec[i] <= 4) {
            dp[i][1] = min(dp[i][1], dp[i-1][2] + 1);
            dp[i][2] = min(dp[i][2], dp[i-1][1] + 1);
        }
    }

    int ans = INF;
    for (int k: {0,1,2}) ans = min(ans, dp[n][k]);
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

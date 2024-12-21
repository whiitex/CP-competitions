#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

const int INF = 1e18;

void solve() {
    int n, k; cin >> n >> k;
    vi a(n+1); for (int i=1; i<=n; ++i) cin >> a[i];
    vi b(n+1); for (int i=1; i<=n; ++i) cin >> b[i];

    vector dp(n+1, vi(2, INF)); // {min_end_a,  min_end_b}
    dp[0][0] = dp[0][1] = 0;
    for (int i=1; i<=n; ++i) {
        if (dp[i-1][0] > k and dp[i-1][1] > k) {
            cout << "NO\n"; return;
        }

        // update min_end_ a [0]
        if (a[i] > b[i]) { // 50, 100, 1
            if (dp[i-1][0] <= k) dp[i][0] = max(1ll, a[i] + dp[i-1][0] - b[i]*k);
            if (dp[i-1][1] <= k) dp[i][0] = min(dp[i][0], max(1ll, a[i] - b[i]*k));
        } else {
            if (dp[i-1][0] <= k and k*a[i] >= b[i]) dp[i][0] = min(dp[i][0], 1ll);
            if (dp[i-1][1] <= k and k*a[i] >= b[i] + dp[i-1][1]) dp[i][0] = min(dp[i][0], 1ll);
        }

        // update min_end_ b [1]
        if (b[i] > a[i]) {
            if (dp[i-1][1] <= k) dp[i][1] = max(1ll, b[i] + dp[i-1][1] - a[i]*k);
            if (dp[i-1][0] <= k) dp[i][1] = min(dp[i][1], max(1ll, b[i] - a[i]*k));
        } else {
            if (dp[i-1][1] <= k and k*b[i] >= a[i]) dp[i][1] = min(dp[i][1], 1ll);
            if (dp[i-1][0] <= k and k*b[i] >= a[i] + dp[i-1][0]) dp[i][0] = min(dp[i][0], 1ll);
        }

    }

    if (dp[n][0] > k and dp[n][1] > k) {
        cout << "NO\n";
    } else cout << "YES\n";
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();
}
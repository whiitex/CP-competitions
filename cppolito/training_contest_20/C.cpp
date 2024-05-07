#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
    int n; cin >> n;
    int h[n][2];
    for (int i=0; i<n; ++i) cin >> h[i][0];
    for (int i=0; i<n; ++i) cin >> h[i][1];

    if (n == 1) {cout << max(h[0][0], h[0][1]) << '\n'; return;}

    int dp[n][2];
    dp[0][0] = h[0][0];
    dp[0][1] = h[0][1];
    dp[1][0] = dp[0][1] + h[1][0];
    dp[1][1] = dp[0][0] + h[1][1];
    for (int i=2; i<n; ++i) {
        dp[i][0] = h[i][0] + max(dp[i-2][1], dp[i-1][1]);
        dp[i][1] = h[i][1] + max(dp[i-2][0], dp[i-1][0]);
    }

    cout << max(dp[n-1][0], dp[n-1][1]) << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t=1; //cin >> t;
    while (t--) solve();
}

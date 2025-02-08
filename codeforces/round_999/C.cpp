#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

const int MOD = 998244353;

void solve() {
    int n; cin >> n;
    vi a(n+1); for (int i=1; i<=n; ++i) cin >> a[i];

    vector dp(n+1, vi(2)); // 0 liar, 1 truth
    dp[1][0] = 1; dp[1][1] = a[1] == 0;
    for (int i=2; i<=n; ++i) {

        // upd liar
        dp[i][0] = dp[i-1][1];

        // upd truth
        if (a[i] == a[i-1]) dp[i][1] = (dp[i][1] + dp[i-1][1]) % MOD;
        if (a[i] == a[i-2] + 1) dp[i][1] = (dp[i][1] + dp[i-1][0]) % MOD;
    }

    cout << (dp[n][0] + dp[n][1]) % MOD << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

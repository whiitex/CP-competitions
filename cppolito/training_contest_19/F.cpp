#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

const int MAXN = 5001;
const int MOD = 998244353;

void solve() {
    int n; cin >> n;
    vi vec(n); for (int &i: vec) cin >> i;

    vi dp(MAXN, 0);
    dp[0] = 1;
    for (int v: vec) {
        for (int i = MAXN - 1; i >= 0; --i) {
            if (dp[i]) dp[i+v] = (dp[i+v] + dp[i]) % MOD;
        }
    }

    int ans = 0;
    for (int i=1; i<MAXN; ++i) {
        if (not dp[i]) continue;

        ans = (ans + ((i+1)/2) * dp[i]) % MOD;

        for (int v: vec) {
            if (v > i-v and i >= v and dp[i-v]) {
                ans = (ans - ((i+1) / 2) * dp[i-v] + MOD) % MOD;
                ans = (ans + v * dp[i-v] + MOD) % MOD;
            }
        }

    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}

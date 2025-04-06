#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 998244353;

int powerlogn(int b, int exp) {
    int mul = b % MOD, ans = 1;
    while (exp) {
        if (exp & 1) ans = (ans * mul) % MOD;
        mul = (1ll * mul * mul) % MOD;
        exp >>= 1;
    } return ans;
}

int inv(int v) {
    return powerlogn(v, MOD-2) % MOD;
}

int dp[2][501][501];
void solve() {
    int n, k; cin >> n >> k;

    dp[0][1][1] = 2;
    for (int i=2; i<=n; ++i) {

        memset(dp[1], 0, sizeof(dp[1]));
        for (int mx=1; mx<i; ++mx) {
            for (int sm=1; sm<=mx; ++sm) {

                int MX = max(sm+1, mx);
                dp[1][sm+1][MX] = (dp[1][sm+1][MX] + dp[0][sm][mx]) % MOD;
                dp[1][1][mx] = (dp[1][1][mx] + dp[0][sm][mx]) % MOD;
            }
        }

        swap(dp[0], dp[1]);
    }

    vector<int> dp2(n+1);
    for (int m=1; m<=n; ++m) {
        for (int i=1; i<=m; ++i) {
            dp2[m] = (dp2[m] + dp[0][i][m]) % MOD;
        }
    }

    vector<int> p(n+1); p[1] = 2;
    for (int i=2; i<=n; ++i) {
        p[i] = (p[i-1] + dp2[i]) % MOD;
    }


    int ans = 0;
    for (int i=1; i<min(k, n+1); ++i) {
        int add = (dp2[i] * p[min(n, (k-1)/i)]) % MOD;
        ans = (ans + add) % MOD;
    }

    cout << ((ans * inv(2)) % MOD) << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();
}

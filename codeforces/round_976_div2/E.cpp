#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

const int MOD = 1e9 + 7;

int powerlogn(int b, int exp) {
    int mul = b % MOD;
    int ans = 1;
    while (exp) {
        if (exp & 1) ans = (ans * mul) % MOD;
        mul = (1ll * mul * mul) % MOD;
        exp /= 2;
    }
    return ans;
}


int inv(int v) {
    return powerlogn(v, MOD-2) % MOD;
}


void solve() {
    int n; cin >> n;
    vi a(n); for (int &i: a) cin >> i;
    vi p(n); for (int &i: p) cin >> i;

    vector dp(2, vi(1024, 0)); dp[0][0] = 1;
    for (int i=0; i<n; ++i) {
        for (int x=0; x<1024; ++x) {
            dp[1][x] = (dp[0][x xor a[i]] * p[i]) % MOD;
            dp[1][x] = (dp[1][x] + dp[0][x] * (10000 - p[i])) % MOD;
        }
        swap(dp[0], dp[1]);
    }

    int ans = 0, den = inv(powerlogn(10000, n));
    for (int i=0; i<1024; ++i) ans = (ans + (dp[0][i] * i*i) % MOD * den) % MOD;

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

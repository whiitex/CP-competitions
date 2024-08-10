#include <bits/stdc++.h>

using namespace std;

#define int long long

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

void solve() {
    int l, r, k; cin >> l >> r >> k;

    int ans = powerlogn(9/k + 1, r) + MOD - powerlogn(9/k + 1, l);
    cout << ans % MOD << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

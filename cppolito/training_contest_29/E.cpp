#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 6;

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
    int n, k; cin >> n >> k;

    vi tre(MAXN, 1), fact(MAXN, 1);
    for (int i=1; i<MAXN; ++i) {
        tre[i] = (tre[i-1] * 3) % MOD;
        fact[i] = (fact[i-1] * i) % MOD;
    }

    if (k == 0) {
        cout << tre[n] << '\n';
        return;
    }

    vi ans(k+1, 0);
    for (int i=1; i<=k; ++i) {
        if (n < k + i - 1) break;
        int kgroups = (fact[k-1] * inv(fact[i-1])) % MOD;
        kgroups = (kgroups * inv(fact[k-1 - (i-1)])) % MOD;

        int ngroupstart = (fact[n-k] * inv(fact[i-1])) % MOD;
        ngroupstart = (ngroupstart * inv(fact[n-k - (i-1)])) % MOD;

        ans[i] = (((kgroups * ngroupstart) % MOD) * tre[n-2*i+1]) % MOD;

        if (n < k + i) continue;
        int ngroups = (fact[n-k] * inv(fact[i])) % MOD;
        ngroups = (ngroups * inv(fact[n-k-i])) % MOD;

        int add = (((kgroups * ngroups) % MOD) * tre[n-2*i]) % MOD;
        ans[i] = (ans[i] + add) % MOD;
    }

    int out = 0;
    for (int i: ans) out = (out + i) % MOD;
    cout << out << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; // cin >> t;
    while (t--) solve();
}

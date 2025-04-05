#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;

const int MAXN = 5e5 + 5;
const int MOD = 998244353;

vector<int> fact(MAXN, 1);
vector<int> invfact(MAXN, 1);

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

void precompute() {
    for (int i=2; i<MAXN; ++i) {
        fact[i] = (fact[i-1] * i) % MOD;
        invfact[i] = inv(fact[i]);
    }
}

void solve() {
    vi a(26); for (int &i: a) cin >> i;

    sort(a.begin(), a.end(), greater<>());

    int tot = 0; for (int i: a) tot += i;
    int div = 1; for (int i: a) if (i) div = (div * invfact[i]) % MOD;

    int even = (tot + 1) / 2, odd = tot / 2;
    vi dp(even+1); dp[0] = 1;
    for (int i=0; i<26; ++i) {
        if (a[i] == 0) break;
        for (int s=even; s >= a[i]; --s) {
            dp[s] = (dp[s] + dp[s - a[i]]) % MOD;
        }
    }

    int ans = (fact[odd] * fact[even]) % MOD;
    ans = (ans * div) % MOD;
    ans = (ans * dp.back()) % MOD;
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    precompute();

    int t = 1; cin >> t;
    while (t--) solve();
}

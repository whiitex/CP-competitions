#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

const int MAXN= 3e5+5;
const int MOD = 998244353;

vector<int> fact(MAXN, 1);
vector<int> invfact(MAXN, 1);
vector<int> two(MAXN);

int powerlogn(int b, int exp) {
    int mul = b % MOD;
    int ans = 1ll;
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

int binomial(int a, int b) {
    int ans = (fact[a] * invfact[b]) % MOD;
    return (ans * invfact[a-b]) % MOD;
}

void precompute() {
    two[0] = 1; two[1] = 2;
    for (int i=2; i<MAXN; ++i) {
        fact[i] = (fact[i-1] * i) % MOD;
        invfact[i] = inv(fact[i]);
        two[i] = (two[i-1] * 2) % MOD;
    }
}

void solve() {
    int n; cin >> n;
    vi vec(n); for (int &i: vec) cin >> i;

    vi freq(n+5); for (int i: vec) ++freq[i];
    vi suff(freq); for (int i=n; i>=0; --i) suff[i] += suff[i+1];

    int ans = 0;
    vector dp(2, vi(n+2));
    for (int i=1; i<= freq[0]; ++i) {
        dp[0][i] = binomial(freq[0], i) % MOD;
        int add = (dp[0][i] * i) % MOD;
        add = (add * two[suff[1]]) % MOD;
        ans = (ans + add) % MOD;
    }

    int mnfreq = freq[0];
    for (int sc=1; sc<=n; ++sc) {

        vi dp0suff(mnfreq+3);
        for (int i=mnfreq; i>0; --i)
            dp0suff[i] = (dp[0][i] + dp0suff[i+1]) % MOD;

        vi takesuff(freq[sc]+2);
        for (int i=freq[sc]; i>0; --i) {
            takesuff[i] = binomial(freq[sc], i);
            takesuff[i] = (takesuff[i] + takesuff[i+1]) % MOD;
        }

        mnfreq = min(mnfreq, freq[sc]);
        for (int i=1; i<=mnfreq; ++i) {
            dp[1][i] = (binomial(freq[sc], i) * dp0suff[i+1]) % MOD;
            dp[1][i] = (dp[1][i] + takesuff[i] * dp[0][i]) % MOD;

            int add = (i * dp[1][i]) % MOD;
            add = (add * two[suff[sc+1]]) % MOD;
            ans = (ans + add) % MOD;
        }

        swap(dp[0], dp[1]);
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    precompute();

    int t = 1; cin >> t;
    while (t--) solve();
}

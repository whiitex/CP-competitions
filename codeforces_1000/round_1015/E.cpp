#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;

#define pb push_back

const int MAXN = 1e4;
const int MOD = 1e9 + 7;

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

int binomial(int a, int b) {
    int ans = (fact[a] * invfact[b]) % MOD;
    return (ans * invfact[a-b]) % MOD;
}

void precompute() {
    for (int i=2; i<MAXN; ++i) {
        fact[i] = (fact[i-1] * i) % MOD;
        invfact[i] = inv(fact[i]);
    }
}

vi prefact(MAXN);

void solve() {
    int n; cin >> n;
    vi a(n+1), cntfree(n+1);
    for (int i=1; i<=n; ++i) {
        cin >> a[i];
        cntfree[i] = cntfree[i-1] + (a[i] == -1);
    }

    vector dp(n+1, vi(n+1)); // dp _x,y: x -1 and up to y count
    for (int i=1, l=n; i<=n; ++i) {
        for (int j=n, r=n; j>=i; --j) {
            int x = cntfree[j] - cntfree[i-1];
            int y = min(l, r);
            ++dp[x][0]; -- dp[x][y];
            if (a[j] != -1) r = min(r, a[j]);
        }
        if (a[i] != -1) l = min(l, a[i]);
    }

    for (int x=0; x<=cntfree[n]; ++x) {
        for (int y=0, k=0; y<=n; ++y) {
            k += dp[x][y];
            dp[x][y] = k;
        }
    }

    vi p(n); for (int i=1; i<=n; ++i) if (a[i] != -1) p[a[i]] = 1;
    for (int i=1; i<n; ++i) p[i] += p[i-1];

    int ans = 0;
    for (int x=0; x<=cntfree[n]; ++x) for (int y=0; y<n; ++y) {
        int bonus = y + 1 - p[y];
        if (bonus > x) break;

        int add = (binomial(x, bonus) * fact[bonus]) % MOD;
        add = (add * fact[cntfree[n] - bonus]) % MOD;
        ans = (ans + dp[x][y] * add) % MOD;
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    precompute();

    int t = 1; cin >> t;
    while (t--) solve();
}

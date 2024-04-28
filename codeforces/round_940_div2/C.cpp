#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

const int MOD = 1e9 + 7;

vi fact(3e5+1);
vi g(3e5+1);
vi two(3e5+1);

int gauss(int n) {
    return ((n * (n+1))/2) % MOD;
}

int powerlogn(int b, int exp) {
    int mul = b;
    int ans = 1;
    while (exp) {
        if (exp & 1) ans = (mul*ans) % MOD;
        mul = (mul*mul) % MOD;
        exp /= 2;
    }
    return ans;
}

int modfract(int b, int mod) {
    if (b == 0 or b == 1) return 1;
    return (powerlogn(b, mod-2) % mod) % mod;
}

void solve() {
    int n, k; cin >> n >> k;
    int diag = 0;
    for (int i=0; i<k; ++i) {
        int a, b; cin >> a >> b;
        if (a == b) ++diag;
    }

    int rem = (n - k*2 + diag) % MOD;

    int ans = 0;
    for (int s=0; s<=rem/2; ++s) {
        int d = rem - s*2;
        int add = (fact[rem] * modfract(fact[rem-d], MOD)) % MOD;
        add = (add * modfract(fact[d], MOD)) % MOD;

        add = (add * g[max(0ll,s*2-1)]) % MOD;
        add = (add * two[s]) % MOD;
        add = (add * modfract(fact[s], MOD)) % MOD;
        ans = (ans + add) % MOD;
    }

    cout << ans%MOD << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    fact[0] = 1;
    for (int i=1; i<(int)3e5+1; ++i) fact[i] = (fact[i-1] * i) % MOD;

    g[0] = g[1] = 1;
    for (int i=2; i<(int)3e5+1; i++) g[i] = (g[i-2] * gauss(i)) % MOD;

    two[0] = 1;
    for (int i=1; i<(int)3e5+1; i++) two[i] = (two[i-1] * 2) % MOD;


    int t; cin >> t;
    while (t--) solve();
}

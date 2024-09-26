#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

const int MAXN = 2e4;
const int MOD = 1e9 + 7;

vi fact(MAXN, 1);
vi invfact(MAXN, 1);

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

int binomial(int a, int b) {
    int ans = (fact[a] * invfact[b]) % MOD;
    return (ans * invfact[a-b]) % MOD;
}

void solve() {
    int n; cin >> n;

    int ans = 0;
    for (int val=1; val<= 2*n + 1; ++val) {
        for (int taken=val/2; taken<val; ++taken) {

            int left = val - 1 - taken;
            int right = taken - left;
            if (left > n or left < 0) continue;
            if (right > 0 and right > n - val) continue;

            int add = binomial(min(n, val - 1), left);

            int mul = 1;
            if (right > 0) mul = binomial(n - val, taken - (val - 1 - taken));

            add = (mul * add) % MOD;
            add = (add * val) % MOD;
            ans = (ans + add) % MOD;
        }
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i=2; i<MAXN; ++i) {
        fact[i] = (fact[i-1] * i) % MOD;
        invfact[i] = inv(fact[i]);
    }

    int t = 1; cin >> t;
    while (t--) solve();
}

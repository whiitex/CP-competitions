#include <bits/stdc++.h>

using namespace std;
#define int long long

typedef vector<int> vi;

const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;

vi num(MAXN), den(MAXN);

int powerlogn(int b, int exp) {
    int mul = b, res = 1;
    while (exp) {
        if (exp & 1) res = (res * mul) % MOD;
        exp >>= 1;
        mul = (mul * mul) % MOD;
    }
    return res % MOD;
}

void solve() {
    int n, px, sx;
    cin >> n >> px >> sx;
    vi pref(px); for (int &i: pref) cin >> i;
    vi suff(sx); for (int &i: suff) cin >> i;

    if (pref[px - 1] != suff[0] or pref[0] != 1 or suff[sx-1] != n) {
        cout << 0 << '\n';
        return;
    }

    int qtsx = suff[0] - 1;
    int qtdx = n - qtsx - 1;

    // suffix
    int right = 1, tot = qtdx, mn = suff[0];
    for (int i = 1; i < sx; ++i) {
        int span = suff[i] - mn;
        right = (right * num[tot - 1]) % MOD;
        right = (right * den[tot - span]) % MOD;

        // update
        mn = suff[i];
        tot -= span;
    }

    // prefix
    int left = 1; tot = qtsx; mn = suff[0];
    for (int i = px - 2; i >= 0; --i) {
        int span = mn - pref[i];
        left = (left * num[tot - 1]) % MOD;
        left = (left * den[tot - span]) % MOD;

        // update
        mn = pref[i];
        tot -= span;
    }

    int ans = (left * right) % MOD;

    int fact = (num[n - 1] * den[qtsx]) % MOD;
    fact = (fact * den[qtdx]) % MOD;
    ans = (ans * fact) % MOD;
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    num[0] = den[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        num[i] = (num[i - 1] * i) % MOD;
        den[i] = powerlogn(num[i], MOD - 2);
    }
    int t; cin >> t;
    while (t--) {
        solve();
    }
}

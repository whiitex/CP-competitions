#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

const int MAXN = 5e5 + 5;
const int MOD = 1e9 + 7;

int two[MAXN];

int to_add(array<int, 3> x) {
    int ans = (x[0] * two[x[1]]) % MOD;
    ans = (ans + x[2] - x[0]) % MOD;
    return (ans + MOD) % MOD;
}

void solve() {
    int n;
    cin >> n;
    vi vec(n);
    for (int &i : vec) cin >> i;

    stack<array<int, 3>> stk; // mx_odd, twos, sm_odd
    int ans = 0;

    for (int i = 0; i < n; ++i) {
        int val = vec[i];
        int twos = __builtin_ctz(val);
        val >>= twos;

        array nw = {val, twos, val};
        ans = (ans + to_add(nw)) % MOD;

        int need = 0, t = 1;
        if (!stk.empty()) while (t * nw[0] < stk.top()[0]) { ++need; t *= 2; }

        while (!stk.empty() && need <= nw[1]) {
            ans = (ans - to_add(nw) + MOD) % MOD;

            nw[1] += stk.top()[1];
            nw[2] += stk.top()[2];

            ans = (ans - to_add(stk.top()) + MOD) % MOD;
            ans = (ans + to_add(nw)) % MOD;

            stk.pop();

            need = 0; t = 1;
            if (!stk.empty()) while (t * nw[0] < stk.top()[0]) { ++need; t *= 2;}
        }

        stk.push(nw);
        cout << ans % MOD << ' ';
    }

    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    two[0] = 1;
    for (int i = 1; i < MAXN; ++i)
        two[i] = (two[i - 1] * 2) % MOD;

    int t;
    cin >> t;
    while (t--) solve();
}

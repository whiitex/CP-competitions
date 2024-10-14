#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;

void solve() {
    int t; cin >> t;
    vi n(t); for (int &i: n) cin >> i;
    vi k(t); for (int &i: k) cin >> i;

    vi two(MAXN, 1);
    for (int i=1; i<MAXN; ++i) {
        two[i] = (two[i-1] * 2) % MOD;
    }

    for (int i=0; i<t; ++i) {
        if (n[i] == k[i] or k[i] == 0) cout << 1 << '\n';
        else {
            cout << two[k[i]] << '\n';
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; // cin >> t;
    while (t--) solve();
}

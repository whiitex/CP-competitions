#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;

const int MOD = 998244353;

void solve() {
    int n; cin >> n;
    vi a(n); for (int &i: a) cin >> i;

    int ans = 0, add = 0, rep = 0, qt = 0;
    for (int i=0; i<n; ++i) {
        if (a[i] == 1) ++rep;
        if (a[i] == 2) {
            add = (add * 2) % MOD;
            add = (add + rep*2) % MOD;
            qt += rep;
            rep = 0;
        }
        if (a[i] == 3) ans = (ans + add - qt + MOD) % MOD;
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

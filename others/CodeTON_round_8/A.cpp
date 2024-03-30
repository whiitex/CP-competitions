#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    if (k == n) {
        for (int i=0; i<n; ++i) cout << 1 << ' ';
        cout << '\n';
    } else if (k == 1) {
        for (int i=1; i<=n; ++i) cout << i << ' ';
        cout << '\n';
    } else cout << -1 << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}

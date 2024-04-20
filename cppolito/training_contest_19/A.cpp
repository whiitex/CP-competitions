#include <bits/stdc++.h>

using namespace std;

void solve() {
    int x, y, k; cin >> x >> y >> k;
    if (y < x) cout << x << '\n';
    else {
        x = min(x+k, y);
        cout << y + y - x << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}

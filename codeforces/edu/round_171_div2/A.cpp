#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int x, y, k; cin >> x >> y >> k;
    if (x < y) {
        cout << 0 << ' ' << 0 << ' ';
        cout << x << ' ' << x << '\n';

        cout << x << ' ' << 0 << ' ';
        cout << 0 << ' ' << x << '\n';
    } else {
        cout << 0 << ' ' << 0 << ' ';
        cout << y << ' ' << y << '\n';

        cout << y << ' ' << 0 << ' ';
        cout << 0 << ' ' << y << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

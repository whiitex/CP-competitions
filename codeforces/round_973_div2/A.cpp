#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, x, y; cin >> n >> x >> y;

    if (x > y) cout << (n + y - 1) /y << '\n';
    else cout << (n+x-1) /x << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

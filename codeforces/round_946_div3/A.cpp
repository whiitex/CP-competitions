#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int x, y; cin >> x >> y;

    int ans = (y+1) / 2;
    int rem = ans * 15 - y * 4;
    x -= rem;
    if (x > 0) ans += (x+14)/15;

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}

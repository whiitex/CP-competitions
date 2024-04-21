#include <bits/stdc++.h>

using namespace std;

void solve() {
    float a, b, c; cin >> a >> b >> c;
    float diff = abs(a-b) / 2;
    int ans = int(diff/c);
    if (diff - float(ans)*c > 0) ++ans;
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}

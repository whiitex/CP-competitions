#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n, b, c; cin >> n >> b >> c;

    if (b + c == 0 and n > 2) { cout << -1 << '\n'; return; }
    if (b == 0) {
        if (c < n-2) { cout << -1 << '\n'; return; }
        if (c < n) cout << n-1 << '\n';
        else cout << n << '\n'; return;
    }

    int ans = n;
    n -= c;
    if (n > 0) ans -= (n + b-1)/b;
    cout << ans << '\n';

}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

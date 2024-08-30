#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int l,r; cin >> l >> r;
    int ans = 0;
    while (l % 2 == 0) ++l;

    while (l + 2 <= r) {
        ++ans;
        l += 4;
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

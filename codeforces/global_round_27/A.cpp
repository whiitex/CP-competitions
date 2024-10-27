#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n, m, r, c; cin >> n >> m >> r >> c;

    int ans = m-c;
    ans += (n-r) * (m-1);
    ans += (n-r) * m;
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

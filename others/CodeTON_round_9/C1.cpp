#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int x, m; cin >> x >> m;

    int cnt = 0;
    for (int i=1; i<=min(10ll*x, m); ++i) if (i != x) {
        int d = i ^ x;
        if (x%d == 0 or i%d == 0) ++cnt;
    }

    cout << cnt << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

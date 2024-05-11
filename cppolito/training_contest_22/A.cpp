#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

void solve() {
    int n, m, x; cin >> n >> m >> x;
    vi sx(n), dx(m);
    for (int &i: sx) cin >> i;
    for (int &i: dx) cin >> i;

    ll ans = 0;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            if (sx[i] + dx[j] <= x) ++ ans;
        }
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
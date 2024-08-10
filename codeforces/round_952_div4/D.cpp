#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

void solve() {
    int n, m, mx = 0, x, y; cin >> n >> m;

    string s;
    for (int i=0; i<n; ++i) {
        cin >> s;
        int count = 0, f=INF, l=-1;
        for (int j=0; j<m; ++j) {
            if (s[j] == '#') {
                f = min(j+1, f);
                l = max(j+1, l);
                ++count;
            }
            if (count % 2 and count > mx) {
                mx = count;
                x = i + 1;
                y = f + l >> 1;
            }
        }
    }

    cout << x << ' ' << y << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

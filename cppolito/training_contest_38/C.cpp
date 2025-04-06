#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

void solve() {
    int n; cin >> n;
    vi vec(n); for (int &i: vec) cin >> i;
    for (int &i: vec) i = abs(i);

    int ans = 0;
    for (int i=0; i<n; ++i) {
        int lx = 0, rx = 0;
        for (int j=0; j<n; ++j) {
            if (vec[j] < vec[i]) {
                if (i < j) ++lx;
                else ++rx;
            }
        }
        ans += min(lx, rx);
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; // cin >> t;
    while (t--) solve();
}

#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int mx=-1, ans, n; cin >> n;

        for (int i=0; i<n; ++i) {
            int q, w; cin >> w >> q;
            if (w < 10 and mx < q) {
                mx = q;
                ans = i+1;
            }
        }
        cout << ans << '\n';
    }
}

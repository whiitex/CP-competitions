#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        ll tot=0, n, a, b, mx = -1; cin >> n;
        
        for (int i=0; i<n; ++i) {
            cin >> a >> b;
            mx = max(mx, max(a, b));
            tot += min(a,b);
        }

        cout << (tot + mx) * 2 << '\n';
    }
}

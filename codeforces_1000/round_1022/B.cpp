#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, x; cin >> n >> x;

    if (n == 1 and x == 0) { cout << -1 << '\n'; return; }
    if (x == 0) {
        if (n & 1) cout << n + 3 << '\n';
        else cout << n << '\n';
        return;
    }

    int cnt = x == 0 ? 0 :__builtin_popcount(x);

    if (cnt > n) cout << x << '\n';
    else {
        n -= cnt;
        if (n & 1 and cnt > 1) ++n, --cnt;

        if (n == 1) {
            int add = 0;
            for (int bt=0; bt<30; ++bt) {
                if ((x >> bt) & 1) continue;
                add = (1 << bt); add <<= 1;
                break;
            }
            cout << x + add << '\n';

        } else if (n & 1 and x & 1) cout << x + n + 3 << '\n';
        else if (n & 1) cout << x + n + 1 << '\n';
        else cout << x + n << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

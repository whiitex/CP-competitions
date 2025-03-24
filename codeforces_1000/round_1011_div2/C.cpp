#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int x, y; cin >> x >> y;

    if (x == y) { cout << -1 << '\n'; return; }

    auto f = [] (int x, int y) -> int {
        for (int bit = 0; bit < 60; ++bit) {

            if ((x & 1) and (y & 1)) return (1ll << bit);

            if ((x & 1) xor (y & 1)) {
                int X = x/2, Y = y/2;
                while ((X & 1) and (Y & 1)) {
                    X >>= 1; Y >>= 1;
                }
                if (!(X & 1) and !(Y & 1)) {
                    return (1ll << bit);
                }
            }

            x >>= 1; y >>= 1;
        }
    };

    int ans = 0;
    while (x & y) {
        int k = f(x, y);
        x += k; y += k;
        ans += k;
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

#define pb push_back

void solve() {
    int b, c, d; cin >> b >> c >> d;

    vi vec;
    while (b > 0 or c > 0 or d > 0) {
        int bitb = b & 1;
        int bitc = c & 1;
        int bitd = d & 1;

        if (bitd == 1) {
            if (bitb == 1 and bitc == 1) vec.pb(0);
            else if (bitb == 0 and bitc == 1) {
                cout << -1 << '\n'; return;
            } else vec.pb(1);
        } else {
            if (bitb == 0 and bitc == 0) vec.pb(0);
            else if (bitb == 0 and bitc == 1) vec.pb(0);
            else if (bitb == 1 and bitc == 1) vec.pb(1);
            else {
                cout << -1 << '\n'; return;
            }
        }

        b >>= 1;
        c >>= 1;
        d >>= 1;
    }

    int two = 1, ans = 0;
    for (int i=0; i<vec.size(); ++i) {
        if (vec[i]) ans += two;
        two <<= 1;
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

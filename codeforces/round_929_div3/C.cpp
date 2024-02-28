#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    ll a, b, l;
    cin >> a >> b >> l;

    ll ans = 0;
    set<ll> st;

    if ((a == 1 and b > 1) or (a > 1 and b == 1)) {
        ll x = max(a, b);
        while (l % (ll) pow(x, ans) == 0) ++ans;
        cout << ans << '\n';
        return;
    }

    int x = 0, y;
    while (l % (ll) pow(a, x) == 0 and b != 1) {

        y = 0;
        while (l % (ll) (pow(b, y) * pow(a, x)) == 0 and b != 1) {
            ll val = l / (ll) pow(a, x) / (ll) pow(b, y);
            if (not st.count(val)) {
                ++ans;
                st.insert(val);
            }
            ++y;
        }
        ++x;
    }

    if (ans == 0) ans = 1;
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

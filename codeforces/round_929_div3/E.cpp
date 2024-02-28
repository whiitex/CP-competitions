#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

void solve() {
    int n; cin >> n;
    vll vec(n+1), gain(n+1);
    for (int i=1; i<=n; ++i) cin >> vec[i];

    gain[0] = 0;
    for (int i=1; i<=n; ++i) gain[i] = gain[i-1] + vec[i];

    int q; cin >> q;
    while (q--) {
        int l, u; cin >> l >> u;
        ll mx_gain = vec[l] * u - vec[l]*(vec[l]-1)/2;

        int lx = l, rx = n;
        while (lx < rx) {
            int mid = (lx + rx + 1) >> 1;
            ll tot = gain[mid] - gain[l-1];
            ll g = u * tot;
            ll r = tot * (tot-1) / 2;

            if (r > g) rx = mid-1;
            else {
                if (g - r > mx_gain) {
                    mx_gain = g-r;
                    lx = mid;
                } else rx = mid - 1;
            }
        }

        ll tot = gain[lx-1] - gain[l-1];
        ll g = u * tot;
        ll r = tot * (tot-1) / 2;
        while (mx_gain <= g - r and lx>l) {
            --lx; mx_gain = g - r;
            tot = gain[lx-1] - gain[l-1];
            g = u * tot;
            r = tot * (tot-1) / 2;
        }
        cout << lx << ' ';
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}

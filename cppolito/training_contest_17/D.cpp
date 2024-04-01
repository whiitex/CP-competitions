#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

#define pb push_back


void solve() {
    ll n; cin >> n;

    vector<bool> is_decreasing(n);
    vll mx_el, vec;
    ll qt_asc = 0;
    for (int i=0; i<n; ++i) {
        int l; cin >> l;

        bool is_dec = true;
        vll v(l); for (ll &q: v) cin >> q;

        ll mn=1e8, mx=-1;
        for (int k=0; k<l; ++k) {

            if (k < l-1 and v[k] < v[k+1]) is_dec = false;
            mn = min(mn, v[k]);
            mx = max(mx, v[k]);
        }

        is_decreasing[i] = is_dec;
        vec.pb(mn);

        if (is_dec) mx_el.pb(mx);
        else ++qt_asc;
    }

    std::sort(mx_el.begin(), mx_el.end());

    ll ans = 0;
    for (int i=0; i<n; ++i) {

        if (is_decreasing[i]) {

            ll l=0, r = (ll) mx_el.size();
            while (l<r) {
                ll mid = l+r >> 1;

                if (mx_el[mid] <= vec[i])
                    l = mid+1;
                else r = mid;
            }

            ans += (ll) mx_el.size() - l;
            ans += qt_asc;
        }
        else ans += n;
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

}

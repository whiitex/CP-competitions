#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi; typedef vector<ll> vll;

void solve() {
    ll n, m, k; cin >> n >> m >> k;
    vll a(n), dfake(m), ffake(k);
    for (ll &i: a) cin >> i;
    for (ll &i: dfake) cin >> i;
    for (ll &i: ffake) cin >> i;

    std::sort(dfake.begin(), dfake.end());
    std::sort(ffake.begin(), ffake.end());

    vll d,f;
    for (int i=0; i<m; ++i) {
        while (i < m-1 and dfake[i] == dfake[i+1]) ++i;
        d.push_back(dfake[i]);
    }

    for (int i=0; i<k; ++i) {
        while (i < k-1 and ffake[i] == ffake[i+1]) ++i;
        f.push_back(ffake[i]);
    }


    ll mx = 0, mx2, num = 0, ind;
    for (int i=1; i<n; ++i) {
        if (a[i] - a[i-1] > mx) {
            mx2 = mx;
            mx = a[i] - a[i-1];
            num = 1;
            ind = i;
        } else if (a[i] - a[i-1] == mx) ++num;

        if (a[i] - a[i-1] > mx2 and a[i] - a[i-1] < mx)
            mx2 = a[i] - a[i-1];
    }

    if (num > 1) {
        cout << mx << '\n';
        return;
    }

    ll ans = 1e11+1;
    ll mn = a[ind-1];
    for (ll dd: d) {
        if (dd >= a[ind]) break;

        int l=0, r=f.size()-1;
        while (l+1 < r) {
            int mid = l+r >> 1;
            if (dd + f[mid] <= (mn + a[ind])/2)
                l = mid;
            else r = mid;
        }

        ans = min(ans, max(dd + f[r] - mn, a[ind] - dd - f[r]));
        ans = min(ans, max(dd + f[l] - mn, a[ind] - dd - f[l]));
    }

    cout << max(min(ans, mx), mx2) << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}

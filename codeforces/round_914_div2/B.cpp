#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
    ll n; cin >> n;
    vector<pair<ll,ll>> vec(n);
    for (ll i=0; i<n; ++i) {
        ll temp; cin >> temp;
        vec[i] = {temp, i};
    }

    sort(vec.begin(), vec.end());
    vector<ll> res(n);
    ll pref_prev = 0;
    ll ind_prev = -1;

    for (ll i=0; i<n-1; ++i) {
        if (ind_prev < i) {
            ind_prev++;
            pref_prev += vec[i].first;
        }

        while (ind_prev<n-1 and pref_prev >= vec[ind_prev+1].first) {
            pref_prev += vec[ind_prev+1].first;
            ind_prev++;
        }

        res[ vec[i].second ] = ind_prev;
    }
    res[vec[n-1].second] = n-1;

    for (auto e: res)
        cout << e << ' ';
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
}

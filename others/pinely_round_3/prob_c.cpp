#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
    ll n; cin >> n;
    vector<pair<ll,ll>> vec(2*n);
    vector<ll> c(n);
    for (ll i=0; i<2*n; ++i) {
        cin >> vec[i].first;
        if (i < n) vec[i].second = 0;
        else vec[i].second = 1;
    }
    std::sort(vec.begin(), vec.end());

    for (ll i=0; i<n; ++i) cin >> c[i];
    std::sort(c.begin(), c.end());
    std::reverse(c.begin(), c.end());

    vector<ll> diff;
    stack<ll> st;
    for (int i=0; i<2*n; ++i) {
        if (vec[i].second == 0) st.push(vec[i].first);
        else {
            ll v = st.top();
            st.pop();
            diff.push_back(vec[i].first - v);
        }
    }

    std::sort(diff.begin(), diff.end());
    ll sum = 0;
    for (int i=0; i<n; ++i) sum += c[i] * diff[i];

    cout << sum << '\n';
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


/*
 *  TLE
    ll n; cin >> n;
    vector<ll> l(n), r(n), c(n);
    for (ll i=0; i<n; ++i) {
        cin >> l[i];
    }
    for (ll i=0; i<n; ++i) {
        cin >> r[i];
    }
    for (ll i=0; i<n; ++i) {
        cin >> c[i];
    }
    sort(c.begin(), c.end());
    reverse(c.begin(), c.end());
    sort(r.begin(), r.end());
    sort(l.begin(), l.end());

    vector<ll> pos(n);
    vector<bool> visl(n), visr(n);
    ll lim = n-1;
    for (ll i=n-1; i>=0 and lim>=0; --i) {
        while (l[i] < r[lim-1] and lim > 0)
            lim--;
        if (l[i] < r[lim]) {
            pos[i] = lim;
            visl[i] = true;
            visr[lim] = true;
            lim--;
        } else {
            int newlim = lim+1;
            while (visr[newlim] and newlim<n-1) newlim++;
            visr[newlim] = true;
            visl[i] = true;
            pos[i] = newlim;
        }
    }

    lim = n-1;
    for (ll i=0; i<n; ++i) if (!visl[i]) {
        while(visr[lim] and lim>0) lim--;
        visr[lim] = true;
        pos[i] = lim;
    }

    vector<ll> diff(n);
    for (ll i=0; i<n; ++i) {
        diff[i] = r[pos[i]] - l[i];
    }

    std::sort(diff.begin(), diff.end());

    ll sum = 0;
    for(ll i=0; i<n; ++i) {
        sum += diff[i] * c[i];
    }

    cout << sum << '\n';
 * */
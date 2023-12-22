#include <bits/stdc++.h>

#define ll long long
using namespace std;

void solve(){
    ll n; cin >> n;
    vector<ll> a(n), b(n);

    for(ll i=0; i<n; i++)
        cin >> a[i];

    for(ll i=0; i<n; i++)
        cin >> b[i];


    // d_min
    int j=0;
    for(ll i = 0; i<n; i++) {
        while (b[j] < a[i]) ++j;
        cout << b[j] - a[i] << ' ';
    }
    cout << '\n';

    // d_max
    ll ia = n-1, ib = n-1;
    vector<ll> ans(n);
    for (ll i=n-1; i>=0; --i) {
        if (ia == i)
            ans[i] = (b[i] - a[i]);
        else {
            if (a[ia] <= b[i]) {
                ans[i] = (b[ib] - a[i]);
                --ia;
            } else {
                ans[i] = (b[i] - a[i]);
                ia = i;
                ib = ia;
            }
        }
    }
    
    for (ll v: ans) cout << v << ' ';
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
}


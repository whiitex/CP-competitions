#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

void solve() {
    ll n; cin >> n;
    map<ll,ll> mp;
    vi vec(n); for (ll& i: vec) {
        cin >> i;
        if (mp.find(i) == mp.end())
            mp.insert({i, 1});
        else ++mp[i];
    }

    ll ans = n;
    for (ll i: vec) {
        if (mp[i]) {
            if (mp.find((1ll<<31)-1-i) != mp.end() and mp[(1ll<<31)-1-i]) {
                --ans;
                --mp[(1ll<<31)-1-i];
            }
            --mp[i];
        }
    }

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

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

const ll MAX_N = 2e5 + 5;
const ll MOD = 1e9 + 7;

ll powlg(ll b, ll exp) { // unused
    ll ans = 1;
    ll mul = b;
    while (exp) {
        if (exp & 1) ans = ans * mul % MOD;
        exp >>= 1;
        mul = mul * mul % MOD;
    }
    return ans & MOD;
}

void solve() {
    string s; cin >> s;
    ll n = (ll)s.length();
    vector<ll> vec(n);
    for (ll i=0; i<n; ++i)
        vec[i] = s[i] - '0';

    ll rx = 0, ans = 0, tenexp = 1;
    for (ll i=n-1; i>=0; --i) {
        ans = ans + ( ( (i * (i+1) >> 1) % MOD * tenexp) % MOD * vec[i] ) % MOD; // sx
        ans = ans + (vec[i] * rx ) % MOD; // rx

        // update dp vars
        rx = (rx + tenexp * (n-i) );
        if (rx > MOD) rx %= MOD; // faster
        tenexp = tenexp * 10;
        if (tenexp > MOD) tenexp %= MOD; // faster
    }

    cout << ans % MOD;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t=1;
//    cin >> t;
    while (t--) {
        solve();
    }
}

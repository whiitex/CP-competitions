#include <bits/stdc++.h>

using namespace std;

#define lll __ll128_t
#define ll long long
#define ld long double

const ll MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;


void solve() {
    ll n; cin >> n;
    vector<ll> vec(n);
    for (ll i=0; i<n; ++i) cin >> vec[i];

    map<ll,bool> m;
    m.insert({0,true});

    ll sum = 0;
    for (ll i=0; i<n; ++i) {
        if (i & 1) sum += vec[i];
        else sum -= vec[i];
        if (m.find(sum) != m.end()) {
            cout << "YES\n";
            return;
        } else m.insert({sum, 1});
    }

    cout << "NO\n";

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

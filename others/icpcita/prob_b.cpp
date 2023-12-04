#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

const ll MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve() {
    ll n; cin >> n;
    ll sol = 3000, temp;
    for (int i=0; i<n; ++i) {
        cin >> temp;
        sol += temp;
    }

    cout << sol;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
}

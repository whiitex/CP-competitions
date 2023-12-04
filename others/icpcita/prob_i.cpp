#include <bits/stdc++.h>

using namespace std;

#define lll __int128_t
#define ll long long
#define ld long double

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;


void solve() {
    ll d, n; cin >> d >> n;
    ll sol = d;

    for (int i=2; i<=n; ++i) {
        sol *= 2;
        sol += i/10 + i%10;
    }

    cout << sol;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
}

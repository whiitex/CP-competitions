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
    ll n; cin >> n;
    ll temp;
    ll sum = 0;
    for(int i=0; i<n; ++i) {
        cin >> temp;
        sum += temp;
    }

    ll side = (ll)sqrt(sum);
    if (side*side == sum) cout << "YES\n";
    else cout << "NO\n";



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

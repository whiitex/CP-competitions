#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

void solve() {
    ll n, d, m, k; cin >> n >> m >> k >> d;
    ll river[n][m];
    ll dp[n][m];
    for (ll i=0; i<n; ++i) {
        for (ll j=0; j<m; ++j) {
            cin >> river[i][j];
            dp[i][j] = 10000000000;
        }
    }

    vi cost(n, 0);

    for (ll i=0; i<n; ++i) {
        multiset<ll> ms;
        for (ll j=0; j<m; ++j) {
            if (j == 0) {
                dp[i][j] = 1;
                ms.insert(1);
                continue;
            }

            dp[i][j] = *ms.begin() + river[i][j]+1;
            ms.insert(dp[i][j]);
            if (ms.size() > d+1) ms.erase(ms.find(dp[i][j-d-1]));
        }
    }
    
    vi pref(n, 0);
    pref[0] = dp[0][m-1];
    for (ll i=1; i<n; ++i) {
        if (i < k) pref[i] = pref[i-1] + dp[i][m-1];
        else {
            pref[i] = pref[i-1] + dp[i][m-1];
            pref[i] -= dp[i-k][m-1];
        }
    }

    ll mn = 10000000000000;
    for (int i=k-1; i<n; ++i) {
        mn = min (pref[i], mn);
    }
    cout << mn << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t; cin >> t;
    while (t--) {
        solve();
    }
}

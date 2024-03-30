#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

#define pb push_back

void solve() {
    ll n, x, y; cin >> n >> x >> y;
    vi vec(x); for (ll& i: vec) cin >> i;
    std::sort(vec.begin(), vec.end());

    if (x+y >= n-1) {
        cout << n-2 << '\n';
        return;
    }

    ll ans = x-2;
    vector<array<ll,3>> distodd;
    vector<array<ll,3>> disteven;

    for (ll i=0; i<x-1; ++i) {
        if (vec[i+1] - vec[i] == 1) continue;

        if (vec[i+1] - vec[i] == 2) ans +=1;
        else if ((vec[i+1] - vec[i]) % 2 == 0)
            disteven.pb({vec[i+1] - vec[i], vec[i], vec[i+1]});
        else distodd.pb({vec[i+1] - vec[i], vec[i], vec[i+1]});
    }

    if (vec[0] + n - vec[x-1] == 2) {
        ans += 1;
    } else if (vec[0] + n - vec[x-1] > 2) {
        if ((vec[0] + n - vec[x-1]) % 2 == 0)
            disteven.pb({vec[0] + n - vec[x-1], vec[x-1], vec[0]});
        else distodd.pb({vec[0] + n - vec[x-1], vec[x-1], vec[0]});
    }

    std::sort(distodd.begin(), distodd.end());
    std::sort(disteven.begin(), disteven.end());

    for (ll i=0; i<disteven.size() and y; ++i) {
        array<ll,3> pp = disteven[i];

        if ( (pp[0]/2 -1) <= y) {
            y -= (pp[0]/2 -1 );
            ans += pp[0] - 1;
        } else {
            ans += 2*y;
            y = 0;
        }
    }

    for (ll i=0; i<distodd.size() and y; ++i) {
        array<ll,3> pp = distodd[i];

        if ( (pp[0]/2) <= y) {
            y -= pp[0]/2 ;
            ans += pp[0] - 1;
        } else {
            ans += 2*y;
            y = 0;
        }
    }


    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t; cin >> t;
    while (t--) {
        solve();
    }
}

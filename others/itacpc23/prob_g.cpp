#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

const ll MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve() {

    ll x, y; cin >> x >> y;
    ll xt, yt; cin >> xt >> yt;
    ll xp, yp; cin >> xp >> yp;
    ll mod = 2*x + 2*y;


    // translation on a one-dimension (circular) road
    ll train;
    if (yt == y) train = xt;
    else if (yt == 0) train = x+y + x-xt;
    else if (xt == x) train = x + y-yt;
    else if (xt == 0) train = 2*x+y + yt;


    // case 1 - up
    ll time1;
    ll pers1 = xp;
    ll tr1 = (train + y-yp) % mod;
    if (tr1 <= pers1)
        time1 = y-yp + pers1-tr1;
    else time1 = y-yp + 2*x + 2*y - (tr1-pers1);

    // case 2 - rx
    ll time2;
    ll pers2 = x + y-yp;
    ll tr2 = (train + x-xp) % mod;
    if (tr2 <= pers2)
        time2 = x-xp + pers2 - tr2;
    else time2 = x-xp +2*x + 2*y - (tr2-pers2);

    // case 3 - down
    ll time3;
    ll pers3 = x+y+ (x-xp);
    ll tr3 = (train + yp) % mod;
    if (tr3 <= pers3)
        time3 = yp + pers3 - tr3;
    else time3 = yp + 2*x + 2*y - (tr3-pers3);

    // case 4 - sx
    ll time4;
    ll pers4 = 2*x + y + yp;
    ll tr4 = (train + xp) % mod;
    if (tr4 <= pers4)
        time4 = xp + pers4-tr4;
    else time4 = xp + 2*x + 2*y - (tr4-pers4);


    // min time
    ll m = LONG_LONG_MAX;
    m = min(m, time1);
    m = min(m, time2);
    m = min(m, time3);
    m = min(m, time4);

    cout << m << '\n';
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

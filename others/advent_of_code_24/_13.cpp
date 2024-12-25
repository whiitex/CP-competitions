#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

const int INF = 1e18;

void solve() {
    int n; cin >> n;

    int ans = 0;
    string s; char c;
    for (int i=0; i<n; ++i) {
        int xa, ya, xb, yb, xp, yp;
        cin >> s >> s; cin >> c >> c;
        cin >> xa; cin >> c >> c;
        cin >> ya;

        cin >> s >> s; cin >> c >> c;
        cin >> xb; cin >> c >> c;
        cin >> yb;

        cin >> s; cin >> c >> c;
        cin >> xp; cin >> c >> c;
        cin >> yp;



        // int x = 0, y = 0, cost = INF;
        // for (int j=0; j<=100; ++j) {
        //     int needx = xp - x, needy = yp - y;
        //     if (needx == 0 and needy == 0) {
        //         cost1 = min(cost, 3*j);
        //     }
        //     else if (needx % xb == 0 and needy % yb == 0 and needx / xb == needy / yb) {
        //         int steps = needx / xb;
        //         cost = min(cost, 3*j + steps);
        //     }
        //
        //     x += xa; y += ya;
        // }
        // if (cost != INF) ans += cost;


        xp += 10000000000000;
        yp += 10000000000000;

        int ii = (yp * xb - xp * yb) / (ya * xb - yb * xa);
        int jj = (xp - ii * xa) / xb;

        if (ii >= 0 and jj >= 0 and ii * xa + jj * xb == xp and ii * ya + jj * yb == yp) {
            ans += 3 * ii + jj;
        }
    }

    cout << ans << '\n';
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();
}

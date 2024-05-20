#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

#define f first
#define s second

void solve() {
    int m, x; cin >> m >> x;
    vpii earn(m);

    for (int i=0; i<m; ++i) {
        pii p;
        cin >> p.f >> p.s;
        earn[i] = p;
    }

    if (m == 1) {
        if (earn[0].f == 0) cout << earn[0].s;
        else cout << 0;
        cout << '\n';
        return;
    }

    int MAXN = 0;
    for (auto p: earn) MAXN += p.s; MAXN += 2000;

    vector<vi> dp(m, vi(MAXN, 0));
    dp[0][0] = x;
    if (earn[0].f == 0) dp[0][earn[0].s] = x;

    for (int d=1; d<m; ++d) {
        for (int h=MAXN-4 ; h>=0; --h) {

            if (h - earn[d].s >= 0 and dp[d-1][h - earn[d].s] >= earn[d].f and dp[d-1][h - earn[d].s]) {
                dp[d][h] = dp[d-1][h - earn[d].s] - earn[d].f + x;
            }

            if (dp[d-1][h]) {
                dp[d][h] = max(dp[d][h], dp[d-1][h] + x);
            }
        }
    }

    int ans = 0;
    for (int i=0; i<MAXN-2; ++i)
        if (dp[m-1][i]) ans = max(ans, i);

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}

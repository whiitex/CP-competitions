#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

#define pb push_back

const int INF = 1e18;

void solve() {
    int n, q; cin >> n >> q;
    vi query; while (q--) {
        int x; cin >> x;
        char c; cin >> c;
        if (c == '+') query.pb(x);
        else query.pb(-x);
    }

    vector mnds(n+1, vi(n+1)); // mnds[i][j] = min dist if i < j
    for (int i=1; i<=n; ++i) for (int j=1; j<=n; ++j) if (i != j) {
        int bonus = 0, dist = 1;
        for (int x: query) {
            if (abs(x) != i and abs(x) != j) continue;
            if (x == j or x == -i) continue;

            if (x == i) {
                if (bonus) --bonus;
                else ++dist;
            } else if (x == -j) ++bonus;
        }

        mnds[i][j] = dist;
    }

    vi tot(n+1);
    for (int i=1; i<=n; ++i) {
        for (int x: query) if (x == i) ++tot[i];
    }

    vector dp((1<<n) + 1, vi(n+1, INF));
    for (int i=0; i<n; ++i) dp[1<<i][i+1] = 1;
    for (int mask=1; mask < (1<<n); ++mask) for (int lst=1; lst<=n; ++lst) {
        for (int nw=0; nw<n; ++nw) {
            if (1 << nw & mask) continue;
            int newmask = (1 << nw) | mask;
            dp[newmask][nw+1] = min(dp[newmask][nw+1], dp[mask][lst] + mnds[lst][nw+1]);
        }
    }

    int ans = INF;
    for (int i=1; i<=n; ++i) ans = min(ans, dp[(1<<n) - 1][i] + tot[i]);
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();
}

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<unsigned,unsigned> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

#define pb push_back
#define st first
#define nd second

const int INF = 8e18;

void solve() {
    int n, m; cin >> n >> m;
    vi a(n); for (int &i: a) cin >> i;
    vector b(n, vector<array<int,3>>());
    for (int i=0, e, t, p; i<m; ++i) {
        cin >> e >> t >> p;
        b[e-1].pb({i+1, t, p});
    }

    int time = 0;
    vi ans;
    for (int i=0; i<n; ++i) {

        map<int,int> convert;
        vector par(201, vector<unsigned>(b[i].size() + 1));
        vector dp(201, vi(b[i].size() + 1, INF));
        dp[0][0] = 0;

        for (int j=1; j<=b[i].size(); ++j) {
            auto [idx, t, p] = b[i][j-1];
            convert[idx] = j;

            for (int k=0; k<201; ++k) {
                dp[k][j] = dp[k][j-1];
                par[k][j] = par[k][j-1];
            }

            for (int x=99; x>=0; --x) {
                if (dp[x+p][j] > dp[x][j-1] + t) {
                    dp[x+p][j] = dp[x][j-1] + t;
                    par[x+p][j] = idx;
                }
            }
        }

        int mn = INF, p = -1, k = (int)b[i].size();
        for (int j=100; j<200; ++j) if (mn > dp[j][k]) {
            mn = dp[j][k], p = j;
        }

        time += mn;
        if (time > a[i]) { cout << -1 << '\n'; return; }

        while (p > 0) {
            int idx = par[p][k];
            ans.pb(idx);
            p -= b[i][convert[idx]-1][2];
            k = convert[idx] - 1;
        }
    }

    cout << ans.size() << '\n';
    for (int i: ans) cout << i << ' ';
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

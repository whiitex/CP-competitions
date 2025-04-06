#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

void solve() {
    int n, m, k; cin >> n >> m >> k; ++k;
    vector<string> g(n); for (string &s: g) cin >> s;

    auto num = [] (char c) -> int { return c - '0'; };

    array<int, 12> neutral; for (int i=0; i<12; ++i) neutral[i] = -1;
    vector dp(n, vector(m, neutral));
    vector p(n, vector(m, neutral)); // 0: left, 1: right

    for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) for (int l=0; l<k; ++l) dp[i][j][l] = -1;
    for (int i=0; i<m; ++i) dp[0][i][ num(g[0][i]) % k ] = num(g[0][i]);

    for (int r=1; r<n; ++r) for (int c=0; c<m; ++c) {
        int value = num(g[r][c]);

        if (c) {
            for (int mod=0; mod<k; ++mod) if (dp[r-1][c-1][mod] != -1){
                if (dp[r-1][c-1][mod] + value > dp[r][c][(mod + value) % k]) {
                    dp[r][c][(mod + value) % k] = dp[r-1][c-1][mod] + value;
                    p[r][c][(mod + value) % k] = 0;
                }
            }
        }

        if (c < m-1) {
            for (int mod=0; mod<k; ++mod) if (dp[r-1][c+1][mod] != -1) {
                if (dp[r-1][c+1][mod] + value > dp[r][c][(mod + value) % k]) {
                    dp[r][c][(mod + value) % k] = dp[r-1][c+1][mod] + value;
                    p[r][c][(mod + value) % k] = 1;
                }
            }
        }
    }

    int ans = -1;
    for (int i=0; i<m; ++i) ans = max(ans, dp[n-1][i][0]);
    cout << ans << '\n';

    if (ans > -1) {
        int x = 0; while (dp[n-1][x][0] != ans) ++x;
        cout << x+1 << '\n';

        for (int i=n-1; i; --i) {
            cout << (p[i][x][ans%k] == 0 ? "L" : "R");
            int newx =  x + (p[i][x][ans%k] == 0 ? -1 : 1);
            ans -= num(g[i][x]);
            x = newx;
        }
    }

}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();
}

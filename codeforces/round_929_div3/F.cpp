#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
const int INF = 1e9;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<bool>> rock;
    int dp[n][m];
    rock.resize(n, vector<bool>(m));
    for (int i=0; i<n; ++i) {
        for (int j = 0; j < m; ++j) {
            bool a; cin >> a;
            rock[i][j] = a;
            dp[i][j] = INF;
        }
    }

    dp[0][0] = 0;
    for (int col = 0; col < m-1; ++col) {

        // fill in the same column
        for (int r = 0; r < 3*n; ++r) {
            int r1 = (r+1) % n;
            int r2 = (r+2) % n;
            if (not rock[r1][col] and not rock[r2][col])
                dp[r2][col] = min(dp[r2][col], dp[r%n][col]+1);
        }

        // go on dx column
        for (int r = 0; r < n; ++r) {
            int r3 = (r+1) % n;
            if (not rock[r3][col+1])
                dp[r3][col+1] = min(dp[r3][col+1], dp[r][col]+1);
        }

    }

    // find the shortest path
    int mn = INF;
    for (int i=0; i<n; ++i) {
        if (dp[i][m-1] == INF) continue;

        int down = (dp[i][m-1] - (m-1)) % n;
        int fin = min(n-down-1, down+1);
        mn = min(mn, dp[i][m-1] + fin);
    }

    if (mn == INF) mn = -1;
    cout << mn << '\n';

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}


/* BAD (but working) RECURSION O(n*m)

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<bool>> grid;
    grid.resize(n, vector<bool>(m));
    for (int i=0; i<n; ++i) {
        for (int j = 0; j < m; ++j) {
            bool a; cin >> a;
            grid[i][j] = a;
        }
    }

    vector<vector<bool>> visited;
    visited.resize(n, vector<bool>(m, false));
    int min_time = INF;
    auto dfs = [&] (auto self, int i, int j, int tm) -> void {
        if (j == m-1) {
            min_time = min(min_time, tm + min(n - i -1, i+1));
            return;
        }
        if (tm > min_time) return;
        if (grid[(i+tm) % n][j]) return;

        for (int row = 0; row < n; ++row) {
            int row1 = (i+row*2+tm)%n;
            int row2 = (i+row*2+tm-1)%n;
            if (row2 < 0) roe2 += n;
            if (grid[row1][j] or grid[row2][j] and row) break;

            if (not visited[(i+row)%n][j+1])
                self(self, (i+row)%n, j+1, tm + row + 1);
        }

    };

    dfs(dfs, 0, 0, 0);
    if (min_time == INF) min_time = -1;
    cout << min_time << '\n';
}

 */
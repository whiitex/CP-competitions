#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
    int n; cin >> n;
    vector<string> gs(n);
    for (string &s: gs) cin >> s;
    int m = (int)gs[0].size();

    vector<vi> grid(n, vi(m));
    for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) grid[i][j] = gs[i][j] - '0';

    vector<vi> vis(n, vi(m));
    auto clear_vis = [&] () -> int {
        int ans = 0;
        for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) {
            ans += vis[i][j];
            vis[i][j] = 0;
        }
        return ans;
    };

    auto count_score = [&] (auto f, int x, int y, int val) -> void {
        if (val != grid[x][y]) return;
        // if (val == 9) { vis[x][y] = 1; return; } // part 1
        if (val == 9) { ++vis[x][y]; return; } // part 2

        for (int dx: {-1, 0, 1}) for (int dy: {-1, 0, 1}) {
            if ((dx == 0 or dy == 0) and x+dx >= 0 and x+dx < n and y+dy >= 0 and y+dy < m) {
                f(f, x+dx, y+dy, val+1);
            }
        }
    };

    int ans = 0;
    for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) {
        count_score(count_score, i, j, 0);
        ans += clear_vis();
    }

    cout << ans << '\n';
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();
}

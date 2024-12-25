#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

void solve() {
    int n; cin >> n;
    vector<string> grid(n);
    for (int i=0; i<n; ++i) cin >> grid[i];
    int m = (int)grid[0].size();

    vector<string> g(n+2); g[0] = g[n+1] = string(m+2, '$');
    for (int i=1; i<=n; ++i) g[i] = "$" + grid[i-1] + "$";

    vector vis(n+2, vi(m+2));
    int area = 0, perimeter = 0;

    // 0-indexed
    auto dfs1 = [&] (auto self, int x, int y) -> void {
        ++area; vis[x][y] = 1;
        for (int dx: {1, 0, -1}) for (int dy: {1, 0, -1}) if (dx == 0 xor dy == 0) {
            if (x + dx >= n or x + dx < 0 or y + dy >= m or y + dy < 0) ++perimeter;
            else {
                if (grid[x+dx][y+dy] != grid[x][y]) ++perimeter;
                else if (!vis[x+dx][y+dy]) self(self, x+dx, y+dy);
            }
        }
    };

    // 1-indexed
    auto dfs2 = [&] (auto self, int x, int y) -> void {
        ++area; vis[x][y] = 1;

        string p;
        vpii d = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for (auto [dx, dy]: d) {
            if (g[x+dx][y+dy] != g[x][y]) p.push_back('1');
            else p.push_back('0');
        }
        for (int i=0; i<4; ++i) p.push_back(p[i]);

        int mx = 0;
        for (int i=0; i<p.size(); ++i) {
            if (p[i] == '0') continue;
            int j = i+1;
            while (j < p.size() and p[j] == '1') ++j;

            mx = max(mx, j-i);
            i = j-1;
        }

        if (mx == 2) perimeter += 1;
        else if (mx == 3) perimeter += 2;
        else if (mx > 3) perimeter += 4;

        char flw = g[x][y];
        if (g[x+1][y] == flw and g[x][y+1] == flw and g[x+1][y+1] != flw) perimeter += 1;
        if (g[x-1][y] == flw and g[x][y+1] == flw and g[x-1][y+1] != flw) perimeter += 1;
        if (g[x+1][y] == flw and g[x][y-1] == flw and g[x+1][y-1] != flw) perimeter += 1;
        if (g[x-1][y] == flw and g[x][y-1] == flw and g[x-1][y-1] != flw) perimeter += 1;

        for (int dx: {1, 0, -1}) for (int dy: {1, 0, -1}) if (dx == 0 xor dy == 0) {
            if (!vis[x+dx][y+dy] and g[x+dx][y+dy] == g[x][y])
                self(self, x+dx, y+dy);
        }
    };

    int ans = 0;
    for (int i=1; i<=n; ++i) for (int j=1; j<=m; ++j) {
        perimeter = area = 0;
        if (!vis[i][j]) dfs2(dfs2, i, j);
        ans += perimeter * area;
    }

    cout << ans << '\n';
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();
}

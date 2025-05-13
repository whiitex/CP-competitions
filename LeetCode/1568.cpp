class Solution {
public:
    int minDays(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        auto cnt_isl = [&n, &m] (vector<vector<int>>& grid) -> int {
            vector<vector<int>> vis(n, vector<int>(m+1));
            int cnt = 0;
            for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) if (!vis[i][j] and grid[i][j]) {
                queue<pair<int,int>> q; q.push({i, j});
                while (!q.empty()) {
                    auto [x, y] = q.front(); q.pop();
                    if (vis[x][y]) continue; vis[x][y] = 1;
                    for (int dx: {-1, 0, 1}) for (int dy: {-1, 0, 1}) if (!dx or !dy) {
                        if (x + dx >= 0 and x + dx < n and y + dy >= 0 and y + dy < m) {
                            if (!vis[x+dx][y+dy] and grid[x+dx][y+dy]) q.push({x+dx, y+dy});
                        }
                    }
                } ++cnt;
            } return cnt;
        };

        int cnt = cnt_isl(grid); if (cnt != 1) return 0;
        for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) if (grid[i][j]) {
            grid[i][j] = 0;
            cnt = cnt_isl(grid);
            if (cnt != 1) return 1;
            grid[i][j] = 1;
        }

        return 2;
    }
};
class Solution {
public:
    int countPyramids(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> up(n, vector<int>(m, 0)), down(n, vector<int>(m, 0));

        for (int i=n-2; i>=0; --i) {
            for (int j=1; j<m-1; ++j) {
                if (!grid[i][j]) continue;
                if (grid[i+1][j-1] and grid[i+1][j] and grid[i+1][j+1]) {
                    int mn = min(up[i+1][j-1], up[i+1][j]);
                    mn = min(mn, up[i+1][j+1]);
                    up[i][j] = mn + 1;
                }
            }
        }

        for (int i=1; i<n; ++i) {
            for (int j=1; j<m-1; ++j) {
                if (!grid[i][j]) continue;
                if (grid[i-1][j-1] and grid[i-1][j] and grid[i-1][j+1]) {
                    int mn = min(down[i-1][j-1], down[i-1][j]);
                    mn = min(mn, down[i-1][j+1]);
                    down[i][j] = mn + 1;
                }
            }
        }

        int ans = 0;
        for (vector<int> v: up) for (int i: v) ans += i;
        for (vector<int> v: down) for (int i: v) ans += i;
        return ans;
    }
};
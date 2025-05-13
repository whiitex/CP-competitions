class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        int n = grid.size(), INF = 1e8;

        // 0: vertical, 1: orizontal
        vector dp(n, vector<array<int,2>>(n, {INF, INF})); dp[0][1][1] = 0;
        priority_queue<array<int,4>> pq; pq.push({0, 0, 1, 1});
        while (!pq.empty()) {
            auto [steps, i, j, p] = pq.top(); pq.pop();
            if (steps > dp[i][j][p]) continue;
            
            int newx = steps + 1;
            if (p == 1) {
                if (j+1 < n and !grid[i][j+1]) {
                    if (dp[i][j+1][1] > newx) {
                        dp[i][j+1][1] = newx;
                        pq.push({newx, i, j+1, 1});
                    }
                }
                if (i < n-1 and !grid[i+1][j] and !grid[i+1][j-1]) {
                    if (dp[i+1][j-1][0] > newx) {
                        dp[i+1][j-1][0] = newx;
                        pq.push({newx, i+1, j-1, 0});
                    }
                    if (dp[i+1][j][1] > newx) {
                        dp[i+1][j][1] = newx;
                        pq.push({newx, i+1, j, 1});
                    }
                }
            } else {
                if (i+1 < n and !grid[i+1][j]) {
                    if (dp[i+1][j][0] > newx) {
                        dp[i+1][j][0] = newx;
                        pq.push({newx, i+1, j, 0});
                    }
                }
                if (j < n-1 and !grid[i-1][j+1] and !grid[i][j+1]) {
                    if (dp[i-1][j+1][1] > newx) {
                        dp[i-1][j+1][1] = newx;
                        pq.push({newx, i-1, j+1, 1});
                    }
                    if (dp[i][j+1][0] > newx) {
                        dp[i][j+1][0] = newx;
                        pq.push({newx, i, j+1, 0});
                    }
                }
            }
        }


        int ans = dp[n-1][n-1][1];
        return ans == INF ? -1 : ans;
    }
};
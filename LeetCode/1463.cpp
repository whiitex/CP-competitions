class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
        dp[0][0][c-1] = grid[0][0] + grid[0][c-1];

        for (int i=1; i<r; ++i) {
            for (int j=0; j<c; ++j) {
                for (int k=j+1; k<c; ++k) {

                    int mx = -1, add = grid[i][j] + grid[i][k];
                    if (j > 0) {
                        if (k > 0 and dp[i-1][j-1][k-1] != -1) mx = max(mx, add + dp[i-1][j-1][k-1]);
                        if (dp[i-1][j-1][k] != -1) mx = max(mx, add + dp[i-1][j-1][k]);
                        if (k < c-1 and dp[i-1][j-1][k+1] != -1) mx = max(mx, add + dp[i-1][j-1][k+1]);
                    }

                    if (k > 0 and dp[i-1][j][k-1] != -1) mx = max(mx, add + dp[i-1][j][k-1]);
                    if (dp[i-1][j][k] != -1) mx = max(mx, add + dp[i-1][j][k]);
                    if (k < c-1 and dp[i-1][j][k+1] != -1) mx = max(mx, add + dp[i-1][j][k+1]);

                    if (j < c-1) {
                        if (k > 0 and dp[i-1][j+1][k-1] != -1) mx = max(mx, add + dp[i-1][j+1][k-1]);
                        if (dp[i-1][j+1][k] != -1) mx = max(mx, add + dp[i-1][j+1][k]);
                        if (k < c-1 and dp[i-1][j+1][k+1] != -1) mx = max(mx, add + dp[i-1][j+1][k+1]);
                    }

                    dp[i][j][k] = mx;
                }                
            }
        }
        
        int ans = 0;
        for (int i=0; i<c; ++i) 
            for (int j=0; j<c; ++j) if (i != j)
                ans = max(ans, dp[r-1][i][j]);
        return ans;
    }
};
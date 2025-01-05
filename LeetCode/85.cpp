class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m));

        for (int j=0; j<m; ++j) {
            for (int i=0; i<n; ++i) {
                if (i == 0) dp[i][j] = matrix[i][j] - '0';
                else if (matrix[i][j] - '0') dp[i][j] = dp[i-1][j] + 1;                
            }
        }

        int ans = 0;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                int h = 10000, w = 0;
                for (int k=j; k>=0 and h>0; --k) {
                    ++w; h = min(h, dp[i][k]);
                    ans = max(ans, w * h);
                }
            }
        }

        return ans;
    }
};
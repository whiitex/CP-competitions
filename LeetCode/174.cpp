class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = (int)dungeon.size(), m = (int)dungeon[0].size();
        const int INF = 100000000;

        int l = max(1, -dungeon[0][0]), r = INF;
        vector dp(n, vector<int>(m));
        while (l < r) {
            int mid = l+r >> 1;

            dp[0][0] = mid + dungeon[0][0];
            for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) {
                if (i or j) dp[i][j] = -INF;
                if (i > 0) dp[i][j] = max(dp[i][j], dp[i-1][j] + dungeon[i][j]);
                if (j > 0) dp[i][j] = max(dp[i][j], dp[i][j-1] + dungeon[i][j]);
                if (dp[i][j] <= 0) dp[i][j] = -INF;
            }

            if (dp[n-1][m-1] > 0) r = mid;
            else l = mid+1;
        }
        return l;
    }
};
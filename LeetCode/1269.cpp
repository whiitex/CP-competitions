class Solution {
    const int MOD = 1e9 + 7;
public:
    int numWays(int steps, int n) {
        if (n == 1) return 1;
        vector<vector<int>> dp(2, vector<int>(n, 0));
        dp[0][0] = 1;

        for (int s=0; s<steps; ++s) {
            for (int i=0; i<min(n, s+2); ++i) {
                dp[1][i] = 0;
                if (i > 0) dp[1][i] = (dp[1][i] + dp[0][i-1]) % MOD;;
                dp[1][i] = (dp[1][i] + dp[0][i]) % MOD;
                if (i < n-1) dp[1][i] = (dp[1][i] +dp[0][i+1]) % MOD;
            }

            swap(dp[0], dp[1]);
        }

        return dp[0][0];
    }
};
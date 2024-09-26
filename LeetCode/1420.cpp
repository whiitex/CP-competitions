class Solution {
    const int MOD = 1e9 + 7;
public:
    int numOfArrays(int n, int m, int k) {
        long long dp[n+1][m+1][k+1];
        memset(dp, 0, sizeof(dp));

        dp[0][0][0] = 1;
        for (int i=1; i<=n; ++i) {
            for (int j=1; j<=m; ++j) {
                for (int q=1; q<=k; ++q) {

                    for (int mx=0; mx<j; ++mx) {
                        dp[i][j][q] += dp[i-1][mx][q-1];
                        dp[i][j][q] %= MOD;
                    }

                    dp[i][j][q] += dp[i-1][j][q] * j;
                    dp[i][j][q] %= MOD;
                }
            }
        }
        
        int ans = 0;
        for (int i=1; i<=m; ++i) ans = (ans + dp[n][i][k]) % MOD;
        return ans;
    }
};
class Solution {
	const int MOD = 1e9+7;
public:
    int checkRecord(int n) {
        
        int dp[2][3][2];
        dp[0][0][0] = 1;

        int x = 1;
        for (int i=1; i<=n; ++i) {
            for (int l=0; l<3; ++l) {
                dp[x][l][0] = 0;dp[x][l][1] = 0; // init

                dp[x][0][0] = (dp[x][0][0] + dp[x^1][l][0]) % MOD; // P

                dp[x][0][1] = (dp[x][0][1] + dp[x^1][l][0]) % MOD; // A
                dp[x][0][1] = (dp[x][0][1] + dp[x^1][l][1]) % MOD; // P
            }

            for (int a=0; a<2; ++a) {
                dp[x][1][a] = (dp[x][1][a] + dp[x^1][0][a]) % MOD; // L
                dp[x][2][a] = (dp[x][2][a] + dp[x^1][1][a]) % MOD; // L
            }
            x ^= 1;
        }

        int ans = 0;
        for (int l=0; l<3; ++l) for (int a=0; a<2; ++a) ans = (ans + dp[x^1][l][a]) % MOD;
        return ans;
    }
};
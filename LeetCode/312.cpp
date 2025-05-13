class Solution {
public:
    int maxCoins(vector<int>& a) {
        int n = a.size();
        int dp[300][300];
        memset(dp, 0, sizeof(dp));

        auto mult = [&] (int l, int i, int r) -> int {
            return a[i] * (l >= 0 ? a[l] : 1) * (r < n ? a[r] : 1);
        };

        for (int span=1; span<=n; ++span) for (int i=0; i<=n-span; ++i) {
            int j = i + span - 1;
            for (int k=i; k<=j; ++k) {
                int lx = k-1 < i ? 0 : dp[i][k-1];
                int rx = k+1 > j ? 0 : dp[k+1][j];
                dp[i][j] = max(dp[i][j], lx + rx + mult(i-1, k, j+1));
            }
        }
        
        return dp[0][n-1];
    }
};
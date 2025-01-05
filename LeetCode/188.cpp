class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector mn(n, vector<int>(n+1, 1e9)); // prefix
        for (int st=0; st<n; ++st) for (int to=st; to>=0; --to)
            mn[st][to] = min(mn[st][to+1], prices[to]);

        vector dp(n+1, vector<int>(k+1, -1e9));
        for (int i=0; i<=n; ++i) dp[i][0] = 0;
        for (int i=0; i<=k; ++i) dp[0][i] = 0;

        for (int ts=1; ts<=k; ++ts) {
            for (int i=0; i<=n; ++i) {

                // maximise dp[i][k]
                for (int p=0; p<i; ++p) {
                    int newval = max(0, prices[i-1] - mn[i-1][p]);
                    dp[i][ts] = max(dp[i][ts], dp[p][ts-1] + newval);
                }
            }
        }

        int ans = 0;
        for (int i=0; i<=n; ++i) for (int j=0; j<=k; ++j)
            ans = max(ans, dp[i][j]);
        return ans;
    }
};
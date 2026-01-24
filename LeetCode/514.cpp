class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n = (int)ring.size(), m = (int)key.size();
        key = '$' + key;

        vector dp(m+1, vector<int>(n, 1e9));
        dp[0][0] = 0;

        for (int k=1; k<=m; ++k) {
            for (int s=0; s<n; ++s) {
                for (int i=-n+1; i<n; ++i) {

                    int p = (s + i + n) % n;
                    if (ring[p] == key[k]) {
                        dp[k][p] = min(dp[k][p], dp[k-1][s] + abs(i));
                    }
                    
                }
            }
        }

        int ans = 1e9;
        for (int i=0; i<n; ++i) if (ring[i] == key.back()) ans = min(ans, dp[m][i]);
        return ans + m;
    }
};
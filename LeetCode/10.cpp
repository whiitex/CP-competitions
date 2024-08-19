class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        p = ' ' + p;
        s = ' ' + s;
        
        bool dp[n+1][m+1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;

        for (int i=1; i<=m; ++i) {
            
            if (i<m and p[i+1] == '*') {
                for (int k=0; k<=n; ++k) {
                    
                    if (dp[k][i-1]) {
                        dp[k][i+1] = 1; ++k;
                        while (k<=n and (s[k] == p[i] or p[i] == '.')) {
                            dp[k][i+1] = 1;
                            ++k;
                        } --k;
                    }
                } ++i;
            } else {
                for (int k = 1; k<=n; ++k) {
                    if (dp[k-1][i-1] and (s[k] == p[i] or p[i] == '.'))
                    dp[k][i] = 1;
                }
            }
        }
        return dp[n][m];
    }
};
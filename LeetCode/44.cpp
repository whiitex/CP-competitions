class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();

        if (n == 0)
            return m == 0 or count(p.begin(), p.end(), '*') == m;
        else if (m == 0) return n == 0;

        bool dp[n][m];
        memset(dp, 0, sizeof(dp));
        int mn = 0;
        for (int j = 0; j < m; ++j) {
            char pj = p[j];
            if (pj == '*') {
                int i=0;
                if (j) while (!dp[i][j-1]) ++i;
                for (; i < n; ++i)
                    dp[i][j] = 1;
            } else {
                int k = -1;
                for (int i = n - 1; i >= mn; --i) {

                    if (pj == '?' and (!i or (i and j and dp[i-1][j-1])))
                        dp[i][j] = 1, k = i;
                    else if (!i and s[i] == pj)
                        dp[i][j] = 1, k = i;
                    else if (i and j and dp[i - 1][j - 1] and s[i] == pj)
                        dp[i][j] = 1, k = i;
                }
                ++mn;
                if (k == -1) break;
                mn = max(mn, k);
            }
        }

        return dp[n-1][m-1];
    }
};
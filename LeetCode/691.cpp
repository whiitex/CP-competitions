class Solution {
public:
    int minStickers(vector<string>& a, string target) {
        int n = (int)target.size();
        vector<int> dp(1<<n, 100000); dp[(1 << n) - 1] = 0;

        for (int mask=(1 << n) - 1; mask>=0; --mask) {
            for (int i=0; i<a.size(); ++i) {
                vector<int> let(26); for (char c: a[i]) ++let[c-'a'];
                int newmask = mask;
                
                for (int j=0; j<n; ++j) if ((mask >> j) & 1) {
                    int pos = n-j-1;
                    if (let[target[pos] - 'a']) {
                        --let[target[pos] - 'a'];
                        newmask -= 1 << j;
                    }

                    dp[newmask] = min(dp[newmask], dp[mask] + 1);
                }
            }
        }

        return dp[0] == 100000 ? -1 : dp[0];
    }
};
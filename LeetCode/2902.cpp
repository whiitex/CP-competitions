class Solution {
public:
    int countSubMultisets(vector<int>& vec, int l, int r) {
        int n = vec.size(), ans = 0;
        vector<int> dp(r+1, 0); dp[0] = 1;
        sort(vec.begin(), vec.end());
        
        for (int i=0; i<n; ++i) {
            int num = vec[i], j = i+1;
            while (j < n and vec[j] == num) ++j;
            if (num == 0) {
                dp[0] = j-i+1;
                i = j-1;
                continue;
            }
            
            for (int k=r-num; k>=0; --k) {
                if (dp[k])
                    for (int rep = 1; rep<=j-i and rep*num + k <=r; ++rep) {
                        dp[k + rep*num] += dp[k];
                        dp[k + rep*num] %= int(1e9 + 7);
                }
            }

            i = j-1;
        }
        for (int i=l; i<=r; ++i) ans = (ans + dp[i]) % int(1e9 + 7);
        return ans;
    }
};
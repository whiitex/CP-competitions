class Solution {
public:
    int sumOfGoodSubsequences(vector<int>& a) {
        int n = (int)a.size(), ans = 0, MOD = 1e9+7;

        vector<long long> f(1e5+2), dp(1e5+2);
        for (int i=0; i<n; ++i) {
            ++f[a[i]]; dp[a[i]] = (dp[a[i]] + a[i]) % MOD; ans = (ans + a[i]) % MOD;
            if (a[i]) f[a[i]] = (f[a[i]] + f[a[i]-1]) % MOD;
            f[a[i]] = (f[a[i]] + f[a[i]+1]) % MOD;
            if (a[i]) dp[a[i]] = (dp[a[i]] + dp[a[i]-1] + a[i] * f[a[i]-1]) % MOD;
            dp[a[i]] = (dp[a[i]] + dp[a[i]+1] + a[i] * f[a[i]+1]) % MOD;
            if (a[i]) ans = (ans + dp[a[i]-1] + a[i] * f[a[i]-1]) % MOD;
            ans = (ans + dp[a[i]+1] + a[i] * f[a[i]+1]) % MOD;
        }

        return ans;
    }
};
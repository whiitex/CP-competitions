class Solution {
public:
    vector<int> maximumSubarrayXor(vector<int>& vec, vector<vector<int>>& queries) {
        int n = vec.size();
        vector<vector<int>> dp(n, vector<int>(n));
        // dp[i][j] xor value for array i..j

        for (int i=0; i<n; ++i) dp[i][i] = vec[i]; // init
        for (int e=1; e<n; ++e) {
            for (int i=0; i<n-e; ++i) {
                dp[i][i+e] = dp[i][i+e-1] ^ dp[i+1][i+e];
            }
        }

        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                dp[i][j] = max(dp[i][j], dp[i][j-1]);
            }
        }

        vector<int> ans;
        for (vector<int> v: queries) {
            int l = v[0], r = v[1], mx = 0;
            for (int i=l; i<=r; ++i) mx = max(mx, dp[i][r]);
            ans.push_back(mx);
        }

        return ans;
    }
};
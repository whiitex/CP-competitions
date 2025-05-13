class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& a, int k) {
        int n = (int)a.size();
        vector<long long> p(n);
        for (int i=0; i<n; ++i) {
            p[i] = a[i];
            if (i) p[i] += p[i-1];
        }

        vector<vector<pair<long long, int>>> dp(n+1, vector<pair<long long, int>>(4));
        for (int x=1; x<=3; ++x) for (int i=n-k*x; i>=0; --i) {
            long long sm = p[i+k-1] - (i ? p[i-1] : 0);
            if (i == n-k*x) dp[i][x] = {sm + dp[i+k][x-1].first, i};
            else {
                if (sm + dp[i+k][x-1].first >= dp[i+1][x].first)
                    dp[i][x] = {sm + dp[i+k][x-1].first, i};
                else dp[i][x] = dp[i+1][x];
            }
        }

        vector<int> ans;
        for (int x=3, i=0; x; --x) {
            ans.push_back(dp[i][x].second);
            i = dp[i][x].second + k;
        }

        return ans;
    }
};
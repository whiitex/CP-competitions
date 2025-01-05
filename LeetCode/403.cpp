class Solution {
public:
    bool canCross(vector<int>& stones) {
        if (stones[1] != 1) return false;
        int n = stones.size();

        unordered_map<int, int> mp;
        for (int i=1; i<n; ++i) mp[stones[i]] = i+1;

        vector dp(n, bitset<2001>()); dp[1][1] = 1;
        for (int s=1; s<n-1; ++s) {
            for (int i=1; i<n+1; ++i) if (dp[s].test(i)) {
                for (int k: {-1, 0, 1}) if (i + k > 0) {
                    int index = mp[stones[s] + i + k] - 1;
                    if (index != -1) dp[index].set(i+k);
                }
            }
        }

        return dp[n-1].any();
    }
};
class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int n = chargeTimes.size(), j = 0, ans = 0;
        long long sum = 0;
        unordered_map<int,int> mp;
        set<int> st;

        for (int i=0; i<n; ++i) {
            sum += runningCosts[i];
            st.insert(chargeTimes[i]);
            ++mp[chargeTimes[i]];
            int k = i + 1 - j;

            while (k and *st.rbegin() + k * sum > budget) {
                sum -= runningCosts[j];
                if (mp[chargeTimes[j]] == 1) st.erase(chargeTimes[j]);
                --mp[chargeTimes[j]];
                --k; ++j;
            }

            ans = max(ans, k);
        }

        return ans;
    }
};
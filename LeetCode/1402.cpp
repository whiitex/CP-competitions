class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end(), greater<>());

        int ans = 0, sum = 0;
        for (int i: satisfaction) {
            if (ans + sum + i > ans) {
                sum += i;
                ans += sum;
            } else break;
        }

        return ans;
    }
};
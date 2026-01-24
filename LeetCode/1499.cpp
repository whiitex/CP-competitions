class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int ans = -1e9;
        multiset<pair<int,int>> x_sum, sum_x;
        for (auto &v: points) {
            while (!x_sum.empty() and x_sum.begin()->first < v[0] - k) {
                auto [x, sum] = *x_sum.begin();
                x_sum.erase(x_sum.begin());
                sum_x.erase(sum_x.find({sum, x}));
            }

            if (!sum_x.empty()) ans = max(ans, v[1] + v[0] + sum_x.rbegin()->first);
            sum_x.insert({v[1] - v[0], v[0]});
            x_sum.insert({v[0], v[1] - v[0]});
        }

        return ans;
    }
};
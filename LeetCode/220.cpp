class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {

        multiset<int> ms;
        int j = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i - j > indexDiff)
                ms.erase(ms.find(nums[j++]));

            if (ms.size()) {
                auto it = ms.lower_bound(nums[i]);
                if (it != ms.end() and abs(nums[i] - *it) <= valueDiff) return true;

                if (it != ms.begin()) {
                    --it;
                    if (abs(nums[i] - *it) <= valueDiff) return true;
                }
            }

            ms.insert(nums[i]);
        }

        return false;
    }
};
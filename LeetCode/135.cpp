class Solution {
public:
    int candy(vector<int>& vec) {
        int ans = 1, more = 0, desc = 0, restore = 0;
        // cout << 1 << ' ';
        for (int i = 1; i < vec.size(); ++i) {
            if (vec[i - 1] > vec[i]) {
                if (more and desc == 0) desc = 1;
                else {
                    if (desc >= more) ++ans;
                    ans += desc++;
                }
                restore = 1;

            } else if (vec[i - 1] < vec[i]) {
                if (restore) more = 0;
                restore = desc = 0;
                ans += ++more;
            
            } else restore = desc = more = 0;
            
            ++ans;
            // cout << ans << ' ';
        }
        return ans;
    }
};
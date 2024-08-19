class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& vec, int k) {
        unordered_map<int,int> mp;
        set<int> st;

        vector<int> ans;
        for (int i=0; i<vec.size(); ++i) {
            ++mp[vec[i]];
            st.insert(vec[i]);

            if (i < k-1) continue;
            if (i >= k) {
                if (mp[vec[i-k]] == 1) st.erase(vec[i-k]);
                --mp[vec[i-k]];
            }

            ans.push_back(*st.rbegin());
        }

        return ans;
    }
};
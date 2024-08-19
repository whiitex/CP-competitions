class Solution {
public:
    int trap(vector<int>& vec) {
        int n = vec.size();
        vector<pair<int,int>> pref(n);

        pref[0].first = 0;
        for (int i=1; i<n; ++i)
            pref[i].first = max(pref[i-1].first, vec[i-1]);
        
        pref[n-1].second = 0;
        for (int i=n-2; i>=0; --i) 
            pref[i].second = max(pref[i+1].second, vec[i+1]);
        
        long long ans = 0;
        for (int i=1; i<n-1; ++i)
            ans += max(0, min(pref[i].first, pref[i].second) - vec[i]);
        
        return ans;
    }
};
class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        
        map<int,int> mp;
        for (int i: a) mp[i]++;
        for (int i: b) mp[i]++;

        int c = 0; float ans;
        if ((a.size() + b.size()) & 1) {
            int goal = (a.size() + b.size() + 1) >> 1;
            for (auto p: mp) {
                if (c + p.second >= goal)
                    return float(p.first);

                c += p.second;
            }
        } else {
            bool f = false;
            int goal = (a.size() + b.size()) >> 1;
            for (auto p: mp) {
                if (f) return ans = float(ans + p.first) / 2.0;

                if (c + p.second > goal)
                    return ans = float(p.first);

                if (c + p.second == goal) {
                    f = true;
                    ans = float(p.first);
                }

                c += p.second;
            }


        }
        return ans;
    }
};
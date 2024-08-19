class Solution {
public:
    int findMin(vector<int>& vec) {
        int n = vec.size();
        int l = 0, r = n-1, m;
        while (l < r) {
            m = l+r >> 1;

            if (vec[r] > vec[m] and vec[m] != vec[l])
                r = m;
            else if (vec[r] < vec[m])
                l = m+1;
            else --r;
        }
        return vec[l];
    }
};
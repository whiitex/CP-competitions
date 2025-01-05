class Solution {
public:
    int splitArray(vector<int>& vec, int k) {
        int l = 0, r = 1e9, n = vec.size();
        for (int i: vec) l = max(l, i);
        while (l < r) {
            int mid = l + r >> 1;
            
            int cnt = 1, sm = 0;
            for (int i: vec) {
                if (sm + i > mid) {
                    ++cnt; sm = i;
                } else sm += i;
            }

            if (cnt > k) {
                l = mid + 1;
            } else r = mid;
        }

        return l;
    }
};
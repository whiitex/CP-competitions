class Solution {
public:
    int firstMissingPositive(vector<int>& vec) {
        vec.push_back(0);
        int n = vec.size();

        bool one = false;
        for (int& i: vec) if (i == 1) {
            one = true;
            i = 0;
        }
        if (!one) return 1;

        for (int i=0; i<n; ++i) {
            int j = vec[i];
            while (j > 1 and j < n) {
                int t = vec[j];
                vec[j] = 1;
                j = t;
            }
        }

        int ans = 2;
        for (int i=2; i<n; ++i) {
            if (vec[i] == 1) ++ans;
            else return ans;
        }
        return ans;
    }
};
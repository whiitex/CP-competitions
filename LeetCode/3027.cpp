class Solution {
    const int INF = 2e9;
public:
    int numberOfPairs(vector<vector<int>>& a) {
        int n = a.size();

        sort(a.begin(), a.end(), [](vector<int>& l, vector<int>& r) -> bool {
            if (l[1] == r[1]) return l[0] < r[0];
            return l[1] > r[1];
        });

        int ans = 0;
        for (int i=0; i<n-1; ++i) {
            int mn = INF, x = a[i][0], y = a[i][1];
            for (int j=i+1; j<n; ++j) {
                if (a[j][0] >= x and a[j][0] < mn) {
                    ++ans;
                    mn = a[j][0];
                }
            }
        }

        return ans;
    }
};
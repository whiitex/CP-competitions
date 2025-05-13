class Solution {
public:
    int maxFrequency(vector<int>& a, int k, int numOperations) {
        int n = (int)a.size(), ans = 0;
        sort(a.begin(), a.end());

        map<int,int> f; for (int i: a) ++f[i];

        for (int i=0, l=0, r=0; i<n; ++i) {
            while (l < i and a[i] - k > a[l]) ++l;
            while ((r < n-1 and a[i] + k >= a[r+1]) or r < i) ++r;
            ans = max(ans, min(numOperations+1 + f[a[i]]-1, r - l + 1));
        }

        for (int i=0, r=0; i<n; ++i) {
            while ((r < n-1 and a[r+1] - k <= a[i] + k) or (r < i)) ++r;
            ans = max(ans, min(numOperations + f[a[i] + k], r - i + 1));
        }

        return ans;
    }
};
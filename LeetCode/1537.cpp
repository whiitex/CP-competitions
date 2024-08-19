typedef long long ll;
const ll MOD = 1e9+7;

class Solution {
public:
    int maxSum(vector<int>& vec1, vector<int>& vec2) {
        int n1 = vec1.size(), n2 = vec2.size();
        
        vector<ll> dp1, dp2;
        ll ct1 = 0, ct2 = 0; int j = 0;
        for (int i=0; i<n1; ++i) {
            int lim = vec1[i];
            while (j < n2 and vec2[j] < lim) {
                ct2 += vec2[j];
                ++j;
            }
            if (j < n2 and vec2[j] == lim) {
                dp2.push_back(ct2);
                dp1.push_back(ct1);
                ct1 = lim;
                ct2 = 0;
            } else ct1 += lim;
        }
        dp1.push_back(ct1);
        while (j < n2) {
            ct2 += vec2[j];
            ++j;
        }
        dp2.push_back(ct2);

        ll ans = 0;
        for (int i=0; i<dp1.size(); ++i) {
            ans = ans + max(dp1[i], dp2[i]);
        }

        return ans % MOD;
    }
};
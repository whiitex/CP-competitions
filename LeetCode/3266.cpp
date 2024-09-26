class Solution {
    const long long MOD = 1e9 + 7;
    long long powerlogn(long long b, long long exp) {
        long long mul = b % MOD;
        long long ans = 1;
        while (exp) {
            if (exp & 1) ans = (ans * mul) % MOD;
            mul = (1ll * mul * mul) % MOD;
            exp /= 2;
        }
        return ans;
    }
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        if (multiplier == 1) return nums;
        int n = nums.size();

        vector<pair<long long,int>> vec; for (long long i=0; i<n; ++i) vec.push_back({nums[i], i});

        sort(vec.begin(), vec.end());
        long long mx = vec[n-1].first;
        
        multiset<pair<long long,int>> ms;
        for (int i=0; i<n-1; ++i) ms.insert(vec[i]);
        while (k > 0 and !ms.empty() and (*ms.begin()).first <= mx) {
            long long val = (*ms.begin()).first;
            long long pos = (*ms.begin()).second;
            ms.erase(ms.begin());
            val *= multiplier;
            ms.insert({val, pos});
            --k;
        }

        ms.insert(vec[n-1]);
        while (!ms.empty()) {
            long long tot = ms.size();
            long long m = (k + tot - 1) / tot;
            k -= m;

            long long val = (*ms.begin()).first;
            int pos = (*ms.begin()).second;
            ms.erase(ms.begin());

            val %= MOD;
            val = (val * powerlogn(multiplier, m)) % MOD;
            nums[pos] = val;
        }

        return nums;
    }
};
class Solution {
public:
    int poorPigs(int buc, int mindie, int min) {
        if (buc == 1) return 0;
        vector<long long> fact(11); fact[0] = 1;
        for (int i=1; i<11; ++i) fact[i] = fact[i-1] * i;
        
        auto bin = [&] (int a, int b) -> long long {
            return fact[a] / fact[b] / fact[a-b];
        };

        vector slides(11, vector<int>(1001));
        for(int i = 0; i < 11; i++) slides[i][0] = 1;
        for(int i = 0; i < 1001; i++) slides[0][i] = 1;
        for (int i=1; i<11; ++i) {
            for (int b=1; b<1001; ++b)
               for (int k=0; k<=i; ++k)
                slides[i][b] += bin(i, k) * slides[i-k][b-1];
        }
        
        int ans = 0; while (slides[ans][min/mindie] < buc) ++ans;
        return ans;
    }
};
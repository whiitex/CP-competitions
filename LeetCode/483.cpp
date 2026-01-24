class Solution {
public:
    string smallestGoodBase(string n) {
        long long N = stoll(n);

        auto count = [&] (long long x, int rep) -> long long {
            long long ans = 0, add = 1;
            while (rep--) {
                ans += add;
                if (rep) {
                    if (to_string(add).size() + to_string(x).size() > 18) return N+1;
                    add *= x;
                }
            }
            return ans;
        };

        for (int len=64; len>2; --len) {
            
            long long l = 2, r = (long long)sqrt(N) + 1ll;
            while (l < r) {
                long long m = l + r >> 1;
                if (count(m, len) >= N) r = m;
                else l = m + 1;
            }

            if (count(l, len) == N) return to_string(l);
        }

        return to_string(N-1);
    }
};
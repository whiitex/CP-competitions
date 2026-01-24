class Solution {
    const int MOD = 1e9 + 7;
public:
    int maxNiceDivisors(int n) {
        if (n <= 4) return n;

        long long ans = 1;

        if (n % 3 == 1) ans = 4, n -= 4;
        else if (n % 3 == 2) ans = 2, n -= 2;

        n /= 3;
        long long mul = 3;
        while (n) {
            if (n & 1) ans = (ans * mul) % MOD;
            n >>= 1, mul = (mul * mul) % MOD;
        }

        return (int)ans;
    }
};
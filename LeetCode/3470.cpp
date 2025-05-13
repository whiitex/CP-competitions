class Solution {
public:
    vector<int> permute(int n, long long k) {
        long long a = n/2, b = n - n/2;
        vector<long long> fact(15, 1);
        for (int i=2; i<15; ++i) fact[i] = fact[i-1] * i;
        if (n < 24) {
            long long tot = fact[a] * fact[b];
            if (a == b) tot *= 2;
            if (k > tot) return {};
        }

        vector<int> ans;
        int first = 1, last = -1;
        while (n - first > 25) {
            ans.push_back(first);
            last = first;
            if (first & 1) --b;
            else --a;
            ++first;
        }

        set<int> avail; for (int i=first; i<=n; ++i) avail.insert(i);
        long long even = a, odd = b, count = 0;

        if (last == -1) {
            if (odd == even) {
                int i = 1;
                for (; i<=n; ++i) {
                    long long add = fact[even - (i & 1 ? 0 : 1)] * fact[odd - (i & 1)];
                    if (count + add >= k) break;
                    count += add;
                } last = i; avail.erase(i);
            } else {
                if (odd > even) {
                    int i = 1;
                    for (; i<=n; i+=2) {
                        long long add = fact[even - (i & 1 ? 0 : 1)] * fact[odd - (i & 1)];
                        if (count + add >= k) break;
                        count += add;
                    } last = i; avail.erase(i);
                } else {
                    int i = 2;
                    for (; i<=n; i+=2) {
                        long long add = fact[even - (i & 1 ? 0 : 1)] * fact[odd - (i & 1)];
                        if (count + add >= k) break;
                        count += add;
                    } last = i; avail.erase(i);
                }
            }
            ans.push_back(last);
            if (last & 1) --odd; else --even;
        }

        while (!avail.empty()) {
            for (int j: avail) if (j % 2 != last % 2) {
                long long add = fact[even - (j & 1 ? 0 : 1)] * fact[odd - (j & 1)];
                if (count + add >= k) {
                    last = j;
                    if (last & 1) --odd; else --even;
                    ans.push_back(last);
                    avail.erase(last);
                    break;
                }
                count += add;
            }
        }

        return ans;
    }
};©leetcode
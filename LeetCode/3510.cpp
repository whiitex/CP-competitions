class Solution {
    typedef long long ll;
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = (int)nums.size();
        
        vector<ll> a(n); for (int i=0; i<n; ++i) a[i] = (ll) nums[i];
        int bad = 0;
        set<pair<ll,int>> st; // sm, idx
        vector<int> nxt(n, -1), prv(n, -1);
        for (int i=0; i<n; ++i) {
            if (i) {
                st.insert({a[i] + a[i-1], i-1});
                bad += a[i-1] > a[i];
            }
            if (i) prv[i] = i - 1;
            if (i < n-1) nxt[i] = i + 1;
        }

        int ans = 0;
        while (bad > 0) {
            ++ans;
            auto [sm, idx] = *st.begin(); st.erase(st.begin());
            
            int before = 0;
            if (prv[idx] != -1) before += a[prv[idx]] > a[idx];
            before += a[idx] > a[nxt[idx]];
            if (nxt[nxt[idx]] != -1) before += a[nxt[idx]] > a[nxt[nxt[idx]]];
            
            if (prv[idx] != -1) {
                st.erase({a[idx] + a[prv[idx]], prv[idx]});
                st.insert({sm + a[prv[idx]], prv[idx]});
            }
            if (nxt[nxt[idx]] != -1) {
                st.erase({a[nxt[idx]] + a[nxt[nxt[idx]]], nxt[idx]});
                st.insert({sm + a[nxt[nxt[idx]]], idx});
            }

            a[idx] = sm;
            nxt[idx] = nxt[nxt[idx]];
            if (nxt[idx] != -1) prv[nxt[idx]] = idx;


            int after = 0;
            if (prv[idx] != -1) after += a[prv[idx]] > a[idx];
            if (nxt[idx] != -1) after += a[idx] > a[nxt[idx]];

            bad += after - before;
        }

        return ans;
    }
};
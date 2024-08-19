class Solution {
    typedef long long ll;
    const ll MOD = 1e9 + 7;

    ll mnlesum(ll mn, ll sum, ll n, ll cost1, ll cost2) {
        ll ans = cost2 * ((mn + sum) / 2);
        if (mn + sum & 1) {
            if (n % 2 == 0) ans += cost1;
            else ans += min((ll)cost1, cost2 * ((n + 1) / 2));
        }
        return ans;
    }

public:
    int minCostToEqualizeArray(vector<int>& vec, int cost1, int cost2) {
        if (vec.size() == 1)
            return 0;
        else if (vec.size() == 2) {
            ll mx = max(vec[0], vec[1]);
            ll mn = min(vec[0], vec[1]);
            return (cost1 * (mx - mn)) % MOD;
        }

        if (2 * cost1 <= cost2) {
            ll mx = -1, ans = 0;
            for (ll i : vec)
                mx = max(mx, (ll)i);
            for (ll i : vec)
                ans = (ans + cost1 * (mx - i)) % MOD;
            return ans;
        }

        ll n = vec.size(), sum = 0;
        ll mxx = vec[0], mnn = vec[0];
        for (int i: vec) {
            sum += (ll) i;
            mxx = max(mxx, (ll)i);
            mnn = min(mnn, (ll)i);
        }
        ll mn = mxx - mnn;
        sum = (n-1) * mxx - sum + mnn;

        if (mn <= sum) return mnlesum(mn, sum, n, cost1, cost2) % MOD;

        ll ans = cost2 * sum + cost1 * (mn - sum);
        ll i = 0, ans2 = 0;
        
        while (mn > sum or ans2 <= ans) {
            ++i;
            sum += n - 2;
            ans2 = i*cost2;

            if (mn <= sum)
                ans2 += mnlesum(mn, sum, n, cost1, cost2);
            else ans2 += cost2 * sum + cost1 * (mn - sum);
            ans = min(ans, ans2);
        }

        return ans % MOD;
    }
};
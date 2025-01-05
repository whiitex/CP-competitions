class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), k=2;
        vector<int> lx(n), rx(n);

        int mn = 1e9;
        for (int i=0; i<n; ++i) {
            lx[i] = max(0, prices[i] - mn);
            if (i) lx[i] = max(lx[i-1], lx[i]);
            mn = min(mn, prices[i]);
        }

        int mx = -1e9;
        for (int i=n-1; i>=0; --i) {
            rx[i] = max(0, mx - prices[i]);
            if (i < n-1) rx[i] = max(rx[i], rx[i+1]);
            mx = max(mx, prices[i]);
        }

        int ans = 0;
        for (int i=0; i<n; ++i) ans = max(lx[i], rx[i]);
        for (int i=0; i<n-1; ++i) {
            ans = max(ans, lx[i] + rx[i+1]);
        }

        return ans;
    }
};
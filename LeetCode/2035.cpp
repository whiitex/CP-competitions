class Solution {
public:
    int minimumDifference(vector<int>& a) {

        int n = (int)a.size() / 2;
        int tot = 0; for (int i: a) tot += i;
        
        auto fill = [&n, &a](int L) -> vector<vector<int>> {
            vector vec(n+1, vector<int>());
            for (int mask=0; mask<1<<n; ++mask) {
                int cnt = 0, sm = 0;
                for (int bit=0; bit<n; ++bit) {
                    if ((mask >> bit) & 1) ++cnt, sm += a[L + bit]; 
                }
                vec[cnt].push_back(sm);
            }
            return vec;
        };
        
        vector<vector<int>> lx = fill(0);
        vector<vector<int>> rx = fill(n);

        int ans = (int)1e9;

        for (int cnt=0; cnt<=n; ++cnt) {
            int ocnt = n - cnt;

            auto calc = [&](int x, int r) -> int {
                return abs(tot - 2 * (x + rx[ocnt][r]));
            };

            sort(lx[cnt].begin(), lx[cnt].end());
            sort(rx[ocnt].begin(), rx[ocnt].end());

            int r = (int)rx[ocnt].size() - 1;

            for (int l=0; l<(int)lx[cnt].size(); ++l) {
                int x = lx[cnt][l];
                
                ans = min(ans, abs(tot - 2 * (x + rx[ocnt][r])));
                while (r > 0 and calc(x, r-1) <= calc(x, r)) {
                    --r;
                    ans = min(ans, calc(x, r));
                }
            }
        }


        return ans;
    }
};
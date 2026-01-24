class Solution {
    const int INF = (int)1e7;
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        for (int i=0; i<m; ++i) if (houses[i] != 0) {
            for (int c=1; c<=n; ++c) cost[i][c-1] = houses[i] == c ? 0 : INF;
        }

        int dp[101][21][102]; // dp _position _color _neighs_so_far
        for (int c=1; c<=n; ++c) dp[0][c][1] = cost[0][c-1];
        for (int c=1; c<=n; ++c) for (int t=2; t<=target; ++t) dp[0][c][t] = INF;

        for (int i=1; i<m; ++i) {
            for (int c=1; c<=n; ++c) for (int t=1; t<=target; ++t) dp[i][c][t] = INF;

            for (int c=1; c<=n; ++c) {
                for (int pc=1; pc<=n; ++pc) for (int pt=1; pt<=target; ++pt) {
                    int nt = pt + (pc != c);
                    dp[i][c][nt] = min(dp[i][c][nt],dp[i-1][pc][pt] + cost[i][c-1]);
                }
            }
        }

        int ans = INF;
        for (int c=1; c<=n; ++c) ans = min(ans, dp[m-1][c][target]);
        return ans < INF ? ans : -1;
    }
};
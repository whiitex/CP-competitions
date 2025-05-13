class Solution {
public:
    long long subtreeInversionSum(vector<vector<int>>& edges, vector<int>& a, int k) {
        int n = edges.size() + 1;
        vector adj(n, vector<int>());
        for (auto& e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> path, tot(n);
        vector<array<long long,3>> dp(n); // max noinv, max inv. min
        vector dep(n, vector<vector<int>>(2, vector<int>())); // dist 1, dist k

        auto dfs = [&] (auto f, int u, int p) -> void {
            tot[u] += a[u];
            if (!path.empty()) dep[path[path.size()-1]][0].push_back(u);
            if (path.size() >= k) dep[path[path.size()-k]][1].push_back(u);

            path.push_back(u);
            for (int v: adj[u]) if (v != p) {
                f(f, v, u);
                tot[u] += tot[v];
            } path.pop_back();

            long long mid = tot[u];
            for (int v: dep[u][1]) mid -= tot[v];

            // dont invert this subtree
            dp[u][0] = a[u];
            for (int v: dep[u][0]) dp[u][0] += max(dp[v][0], dp[v][1]);

            // invert this subtree
            dp[u][1] = -mid;
            for (int v: dep[u][1]) dp[u][1] += -dp[v][2];

            // min possible
            long long noinv = a[u];
            for (int v: dep[u][0]) noinv += dp[v][2];
            long long inv = -mid;
            for (int v: dep[u][1]) inv += -max(dp[v][0], dp[v][1]);
            dp[u][2] = min(noinv, inv);
        };
        
        dfs(dfs, 0, -1);
        
        return max(dp[0][0], dp[0][1]);
    }
};
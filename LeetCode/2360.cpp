class Solution {
public:
    int longestCycle(vector<int>& adj) {
        int n = (int)adj.size();

        int ans = -1;
        vector<int> vis(n);
        auto dfs = [&](auto f, int u, int timer) -> void {
            vis[u] = -timer;
            if (adj[u] != -1 and vis[adj[u]] <= 0) {
                if (vis[adj[u]] < 0) ans = max(ans, timer + vis[adj[u]] + 1);
                else f(f, adj[u], timer + 1);
            }
            vis[u] = timer;
        };

        for (int i=0; i<n; ++i) if (!vis[i]) dfs(dfs, i, 1);

        return ans;
    }
};
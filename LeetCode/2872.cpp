class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {

        vector adj(n, vector<int>());
        for (auto &v: edges) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }

        int ans = 0;
        auto dfs = [&] (auto f, int u, int p=-1) -> int {
            int sm = values[u] % k;
            for (int v: adj[u]) if (v != p) sm = (sm + f(f, v, u)) % k;

            if (sm == 0) ++ans;
            return sm;
        }; dfs(dfs, 0);

        return ans;
    }
};
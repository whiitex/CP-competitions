typedef pair<int,int> pii;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int src, int trg) {
        
        if (src == trg) return 0;

        map<int, vector<int>> bus;
        for (int r=0; r<routes.size(); ++r) {
            for (int b: routes[r]) 
                bus[b].push_back(r);
        }
        
        queue<pii> q;
        vector<bool> bus_vis(1e6, 0);
        vector<bool> route_vis(500, 0);
        for (int r: bus[src]) q.push({r, 1});

        while (!q.empty()) {
            pii node = q.front(); q.pop();
            int route = node.first;
            int depth = node.second;

            if (route_vis[route]) continue;
            route_vis[route] = 1;

            for (int b: routes[route]) {
                if (b == trg) return depth;
                if (bus_vis[b]) continue;
                for (int r: bus[b])
                    if (!route_vis[r])
                        q.push({r, depth+1});
                bus_vis[b] = 1;
            }
        }

        return -1;
    }
};
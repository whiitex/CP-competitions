#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define pb push_back

const int INF = 1e9+7;

string solve() {
    int n, a, b; cin >> n >> a >> b;
    vector<vi> adj(n+1);
    for (int i=0; i<n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    if (a == b) return "No";


    vector<bool> visited(n+1, 0);
    int meetPoint = 0;
    auto dfs = [&] (int node, int par, auto const& dfs) -> void {
        visited[node] = 1;
        for (int child: adj[node]) {
            if (child == par) continue;

            if (!visited[child])
                dfs(child, node, dfs);
            else if (!meetPoint)
                meetPoint = child;
        }
    };

    dfs(b, 0, dfs);

    queue<pii> q;
    function<int()> bfs = [&] () -> int {
        while (!q.empty()) {
            int node = q.front().first;
            int dept = q.front().second;
            q.pop();

            if (node == meetPoint) return dept;
            for (int child: adj[node])
                if (not visited[child]) {
                    q.emplace(child, dept + 1);
                    visited[child] = 1;
                }
        }
    };

    for (int i=0; i<=n; ++i) visited[i] = 0;
    q.emplace(a, 0);
    int dist_a = bfs();

    for (int i=0; i<=n; ++i) visited[i] = 0;
    while(not q.empty()) q.pop();
    q.emplace(b, 0);
    int dist_b = bfs();

    if (dist_b < dist_a) return "Yes";
    else return "No";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) cout << solve() << '\n';

}

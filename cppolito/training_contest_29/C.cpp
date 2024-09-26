#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

#define pb push_back


void solve() {
    int n; cin >> n;
    vector<vi> adj(n+1, vi());

    for (int i=1; i<=n; ++i) {
        int v; cin >> v;
        if (v != 0) {
            adj[v].pb(i);
            adj[i].pb(v);
        }
    }

    int u = 1;
    while (adj[u].size() > 1) ++u;

    vi ans;
    stack<int> rem;
    auto dfs = [&] (auto f, int node, int par) -> int {
        int connections = par != 0, nodes = 1;
        for (int ch: adj[node]) if (ch != par) {
            int nd = f(f, ch, node);
            if (nd != 0) {
                nodes += nd;
                ++connections;
            }
        }

        rem.push(node);
        if (connections % 2 == 0) {
            for (int i=0; i<nodes; ++i) {
                ans.pb(rem.top());
                rem.pop();
            }
            return 0;
        } return nodes;
    };

    dfs(dfs, u, 0);

    if (ans.size() == n) {
        cout << "YES\n";
        for (int i: ans) cout << i << ' ';
    } else cout << "NO";

    cout << '\n';

}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; // cin >> t;
    while (t--) solve();
}

#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

#define pb push_back

void solve() {
    int n, m; cin >> n >> m;
    vector adj(n+1, set<int>());
    for (int i=0; i<m; ++i) {
        int u, v; cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    if (m == 0) { cout << 0 << '\n'; return; }

    vector<array<int,3>> ans;
    for (int i=1; i<=n; ++i) {
        while (adj[i].size() > 1) {
            int u = *adj[i].begin();
            adj[i].erase(adj[i].begin());
            int v = *adj[i].begin();
            adj[i].erase(adj[i].begin());

            adj[u].erase(i);
            adj[v].erase(i);

            if (adj[u].contains(v)) {
                adj[u].erase(v); adj[v].erase(u);
            } else {
                adj[u].insert(v); adj[v].insert(u);
            }

            ans.pb({i, u, v});
        }
    }

    set<int> tree, free;
    vi skip(n+1);
    for (int i=1; i<=n; ++i) {
        if (adj[i].empty()) free.insert(i);
        else if (!skip[i]) {
            tree.insert(i);
            skip[*adj[i].begin()] = 1;;
        }
    }


    if (free.size() != n) {
        int t = *tree.begin();
        tree.erase(tree.begin());
        int v = *adj[t].begin();

        while (!tree.empty()) {
            int tt = *tree.begin();
            tree.erase(tree.begin());
            int vv = *adj[tt].begin();
            ans.pb({t, v, tt});
            t = tt;
            v = vv;
        }

        for (int i: free) {
            ans.pb({t, v, i});
            v = i;
        }
    }

    cout << ans.size() << '\n';
    for (auto [a,b,c]: ans) cout << a << ' ' << b << ' ' << c << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

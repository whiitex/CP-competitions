#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

#define pb push_back

void solve() {
    int n; cin >> n;
    int a, b; cin >> a >> b;
    vector<vi> adj (n+1, vi());
    for (int i=0; i<n-1; ++i) {
        int v, u; cin >> v >> u;
        adj[v].pb(u);
        adj[u].pb(v);
    }

    if (n == 1) {
        cout << 0 << '\n';
        return;
    }

    // PARENTING THE TREE FROM b
    vi par(n+1);
    auto parenting = [&] (auto self, int node, int p) -> void {
        for (int ch: adj[node]) if (ch != p) {
            par[ch] = node;
            self(self, ch, node);
        }
    };
    parenting(parenting, b, 0);


    // DISTANCE BETWEEN a AND b
    int distab;
    auto dfs1 = [&] (auto self, int node, int par, int d) {
        for (int ch: adj[node]) if (ch != par) {
            if (ch == a) {
                distab = d;
                return;
            }
            else self(self, ch, node, d+1);
        }
    };

    if (a == b) distab = 0;
    else dfs1(dfs1, b, 0, 1);

    int c = a;
    for (int i=0; i< distab/2; ++i)
        c = par[c];


    // MAX DEPTH FROM c
    auto dfs2 = [&] (auto self, int node, int par) -> int {
        int mx = -1;
        for (int ch: adj[node]) if (ch != par) {
            mx = max(mx, self(self, ch, node));
        }
        return mx + 1;
    };

    int lb = dfs2(dfs2, c, 0);

    int ans = (distab+1)/2;
    ans += (n-1) * 2;
    ans -= lb;

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}

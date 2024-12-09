#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

#define pb push_back

void solve() {
    int n; cin >> n;
    vector adj(n, vi());
    for (int i=0; i<n-1; ++i) {
        int u, v; cin >> u >> v;
        --u; --v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vi ans(n);
    int x = 1;
    auto dfs = [&] (auto dfs, int u, int p=-1) -> void {
        int first = 1;
        ans[u] = x;

        for (int v: adj[u]) if (v != p) {
            if (first) {
                first = 0;
                ++x;
                dfs(dfs, v, u);
                ++x;
            } else {
                ans[v] = x;
                x += 2;
                dfs(dfs, v, u);
            }
        }
    };
    dfs(dfs, 0);

    for (int i: ans) cout << i << ' ';
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

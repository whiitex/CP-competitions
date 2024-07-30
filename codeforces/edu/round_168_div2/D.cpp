#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

#define pb push_back

const int INF = 1e9 + 9;

void solve() {
    int n; cin >> n;
    vector<vi> adj(n+1, vi());
    vi a(n+1);

    for (int i=1; i<=n; ++i) cin >> a[i];
    for (int i=2; i<=n; ++i) {
        int u; cin >> u;
        adj[u].pb(i);
    }

    auto dfs = [&] (auto dfs, int node) -> int {
        int mn = INF;
        for (int ch: adj[node]) {
            int k = dfs(dfs, ch);
            mn = min(mn, k);
        }

        if (node == 1) return mn;
        if (mn == INF) return a[node];
        if (mn > a[node]) return (mn + a[node]) / 2;
        return mn;
    };

    cout << a[1] + dfs(dfs, 1) << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

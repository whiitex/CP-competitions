#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

#define pb push_back

const int MOD = 998244353;

int dp[2001];

void solve() {
    int n, q; cin >> n >> q;
    vector adj(n, vi());
    for (int i=1; i<n; ++i) {
        int u, v; cin >> u >> v;
        adj[u-1].pb(v-1);
        adj[v-1].pb(u-1);
    }

    vi dep(n), deg(n), par(n);
    auto dfs = [&] (auto dfs, int u, int p=-1) -> void {
        deg[u] = adj[u].size();
        for (int v: adj[u]) if (v != p) {
            par[v] = u;
            dep[v] = dep[u] + 1;
            dfs(dfs, v, u);
        }
    };
    dfs(dfs, 0);

    int v, p;
    while (q--) {
        cin >> v >> p; --v;
        int steps = dep[v];

        vi degs; int odd = 1;
        while (v != 0) {
            if (!odd) degs.pb(deg[v]);
            v = par[v];
            odd ^= 1;
        }

        if (degs.size() <= p) { cout << steps << '\n'; continue; }

        sort(degs.begin(), degs.end());
        int ans = steps;
        for (int i=0; i<(int)degs.size()-p; ++i) {
            ans = (ans + dp[degs[i]] - 1 + MOD) % MOD;
        }

        cout << ans << '\n';
    }

}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    dp[1] = 1;
    for (int i=2; i<=2000; ++i) {
        dp[i] = (2*i - 1) % MOD;
    }

    int t = 1; cin >> t;
    while (t--) solve();
}

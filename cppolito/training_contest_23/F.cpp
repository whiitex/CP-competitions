#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

#define pb push_back

const int MOD = 1e9+7;
const int MAXN = 2e5+5;

int two[MAXN];
int dp[MAXN];

void solve() {
    int n; cin >> n;
    vector<vi> adj(n+1, vi());
    for (int i=0; i<n-1; ++i) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    int ans = dp[n];
    vi ct_live(n+1, 0);

    auto dfs = [&] (auto self, int node, int par) -> int {
        int mx = 0;
        for (int ch: adj[node]) if (ch != par) {
            mx = max(mx,self(self, ch, node));
        }
        ct_live[node] = mx;
        return ct_live[node] + 1;
    };

    dfs(dfs, 1, 0);
    for (int i: ct_live) if (i)
        ans = (ans + two[n-1] * i) % MOD;

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    two[0] = 1, dp[0] = 0;
    for (int i = 1; i < MAXN; ++i) {
        two[i] = (2 * two[i - 1]) % MOD;
        dp[i] = (dp[i - 1] * 2 + two[i - 1]) % MOD;
    }

    int t; cin >> t;
    while (t--) solve();
}

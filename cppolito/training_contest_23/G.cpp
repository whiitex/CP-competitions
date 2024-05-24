#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

#define pb push_back

void solve() {
    int n, k; cin >> n >> k;
    vector<vi> adj(n+1, vi());
    for (int i=2; i<=n; ++i) {
        int v; cin >> v;
        adj[i].pb(v);
        adj[v].pb(i);
    }

    int tot, mid;
    auto dfs = [&] (auto self, int node, int par) -> int {
        int mx = 1;
        for (int ch: adj[node]) if (ch != par) {
            mx = max(mx, self(self, ch, node));
        }

        if (mx == mid and par != 1 and node != 1) {
            ++ tot; return 1;
        }
        return mx+1;
    };

    int l=1, r=2e5+5;
    while (l < r) {
        mid = l+r >> 1;

        tot = 0;
        dfs(dfs, 1, 0);

        if (tot > k) l = mid + 1;
        else r = mid;
    }

    cout << l << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}

#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;

#define pb push_back

void solve() {
    int n; cin >> n;

    map<pii, int> mp;
    vector<vi> adj(n+1, vi());
    for (int i=0; i<n-1; ++i) {
        int u, v; cin >> u >> v;
        adj[v].pb(u);
        adj[u].pb(v);
        mp[{min(u,v), max(u,v)}] = i;
    }

    bool bamboo = true;
    for (int i=1; i<=n; ++i) if (adj[i].size() > 2) bamboo = false;

    if (bamboo) {
        for (int i=0; i<n-1; ++i)
            cout << i << '\n';
    } else {
        vi ans(n-1, -1);
        int node = 1;
        while (adj[node].size() < 3) ++node;

        for (int k=0; k<3; ++k) {
            int mn = min(node, adj[node][k]);
            int mx = max(node, adj[node][k]);
            int index = mp[{mn, mx}];
            ans[index] = k;
        }

        int val = 3;
        for (int i=0; i<n-1; ++i) if (ans[i] == -1) ans[i] = val++;
        for (int i: ans) cout << i << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t=1; // cin >> t;
    while (t--) solve();
}

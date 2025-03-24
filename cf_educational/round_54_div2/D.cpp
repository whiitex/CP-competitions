#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

#define pb push_back
#define st first
#define nd second

pii mkp(int a, int b) { return {min(a,b), max(a,b)}; }

void solve() {
    int n, m, k; cin >> n >> m >> k;
    map<pii, int> mp;
    vector adj(n+1, vpii());
    for (int i=0; i<m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
        mp[mkp(u,v)] = i+1;
    }

    if (k > m) {
        cout << m << '\n';
        for (int i=1; i<=m; ++i) cout << i << ' ';
        return;
    }

    priority_queue<array<int,3>, vector<array<int,3>>, greater<>> pq;
    for (pii p: adj[1]) pq.push({p.nd, p.st, 1});
    vi vis(n+1), par(n+1), ans; vis[1] = 1;
    while (ans.size() < k and !pq.empty()) {
        auto [value, u, par] = pq.top(); pq.pop();

        if (vis[u]) continue;
        vis[u] = 1;
        ans.pb(mp[mkp(u, par)]);

        for (pii p: adj[u]) if (!vis[p.st]) {
            pq.push({p.nd + value, p.st, u});
        }
    }

    cout << ans.size() << '\n';
    for (int i: ans) cout << i << ' ';
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();
}
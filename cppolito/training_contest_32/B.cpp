#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

#define pb push_back
#define f first
#define s second

const int INF = 1e18;

void solve() {
    int n, m; cin >> n >> m;
    vector<vpii> adj(n+1, vpii());
    for (int i=0; i<m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    vi a(n+1, INF); for (int i=1; i<=n; ++i) cin >> a[i];

    priority_queue<pii, vpii, greater<>> pq;
    for (int i=1; i<=n; ++i) if (!adj[i].empty()) pq.push({a[i], i});
    vector<bool> visited(n+1, 0);
    while (!pq.empty()) {
        auto p = pq.top(); pq.pop();
        int cost = p.f, u = p.s;

        if (visited[u]) continue;
        visited[u] = true;

        for (pii pc: adj[u]) if (!visited[pc.f]) {
            int v = pc.f, w = pc.s;
            int newval = 2 * w + cost;
            if (a[v] > newval) {
                a[v] = newval;
                pq.push({newval, v});
            }
        }
    }

    for (int i=1; i<=n; ++i) cout << a[i] << ' ';
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; // cin >> t;
    while (t--) solve();
}

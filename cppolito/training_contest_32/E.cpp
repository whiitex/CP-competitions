#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

#define pb push_back
#define f first
#define s second

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 1e18;

void solve() {
    int n, m; cin >> n >> m;
    vector adj(n+1, vpii());
    vector<tuple<int,int,int>> edges;

    vector dist(n+1, vi(n+1, INF));
    for (int i=1; i<=n; ++i) dist[i][i] = 0;
    for (int i=0; i<m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
        edges.pb({u, v, w});
        dist[u][v] = 1;
        dist[v][u] = 1;
    }

    for (int k=1; k<=n; ++k) {
        for (int i=1; i<=n; ++i) {
            for (int j=1; j<=n; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int ans = INF;
    for (auto [u, v, w]: edges) {

        int distance = INF;
        for (int i=1; i<=n; ++i) {
            int d = dist[1][i] + dist[n][i] + min(dist[u][i], dist[v][i]) + 1;
            distance = min(distance, d);
        }
        int mul = distance + 1;
        ans = min(ans, w * mul);

        mul = min(dist[1][u] + dist[n][v], dist[n][u] + dist[1][v]) + 1;
        ans = min(ans, w * mul);
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

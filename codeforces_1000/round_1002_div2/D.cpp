#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;

#define pb push_back
#define st first
#define nd second

const int INF = 1e18;

void solve() {
    int n, s1, s2; cin >> n >> s1 >> s2; --s1, --s2;
    vector g1(n, vi()), g2(n, vi());
    int m1; cin >> m1;
    for (int i=0; i<m1; ++i) {
        int u, v; cin >> u >> v; --u, --v;
        g1[u].pb(v);
        g1[v].pb(u);
    }
    int m2; cin >> m2;
    for (int i=0; i<m2; ++i) {
        int u, v; cin >> u >> v; --u, --v;
        g2[u].pb(v);
        g2[v].pb(u);
    }

    set<int> good;
    for (int i=0; i<n; ++i) {
        for (int v: g1[i]) for (int u: g2[i]) {
            if (v == u) good.insert(v), good.insert(u);
        }
    }

    vector d(n, vi(n));
    for (int u=0; u<n; ++u) for (int v=0; v<n; ++v) {
        d[u][v] = abs(v - u);
    }

    // dijkstra
    vector vis(n, vi(n, INF)); vis[s1][s2] = 0;
    priority_queue<pair<int, pii>> pq; pq.push({0, {s1, s2}});
    while(!pq.empty()) {
        int cost = pq.top().st; cost = -cost;
        auto [u1, u2] = pq.top().nd;
        pq.pop();

        if (vis[u1][u2] < cost) continue;

        for (int to1: g1[u1]) for (int to2: g2[u2]) {
            if (cost + d[to1][to2] < vis[to1][to2]) {
                pq.push({-(cost + d[to1][to2]), {to1, to2}});
                vis[to1][to2] = cost + d[to1][to2];
            }
        }
    }

    int ans = INF;
    for (int i: good) ans = min(ans, vis[i][i]);
    if (ans == INF) ans = -1;
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}
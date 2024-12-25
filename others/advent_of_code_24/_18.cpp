#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

#define pb push_back

const int INF = 1e18;

void solve() {
    int N; cin >> N;
    int n = 70;
    vector g(n+1, vi(n+1, 1));
    for (int i=0; i<1024; ++i) {
        int u, v; cin >> u >> v;
        g[u][v] = 0;
    }

    // part 1
    priority_queue<array<int,3>, vector<array<int,3>>, greater<>> pq;
    pq.push({0, 0, 0});
    vector vis(n+1, vi(n+1)), dp(n+1, vi(n+1, INF));
    while (!pq.empty()) {
        auto [pen, x, y] = pq.top(); pq.pop();

        if (vis[x][y]) continue;
        vis[x][y] = 1; dp[x][y] = pen;

        if (x > 0 and !vis[x-1][y] and g[x-1][y]) pq.push({pen + 1, x-1, y});
        if (y > 0 and !vis[x][y-1] and g[x][y-1]) pq.push({pen + 1, x, y-1});
        if (x < n and !vis[x+1][y] and g[x+1][y]) pq.push({pen + 1, x+1, y});
        if (y < n and !vis[x][y+1] and g[x][y+1]) pq.push({pen + 1, x, y+1});
    }
    cout << dp[n][n] << '\n';


    // part 2
    auto clear_vis = [&] () -> void {
        for (vi& v: vis) for (int& i: v) i = 0;
    };

    int dex=0, top=0;
    auto dfs = [&] (auto f, int x, int y) -> void {
        if (x == 0) dex = 1;
        if (y == n) top = 1;
        vis[x][y] = 1;

        for (int dx: {-1,0,1}) for (int dy: {-1,0,1}) {
            if (x+dx >= 0 and x+dx <= n and y+dy >= 0 and y+dy <= n) {
                if (!vis[x+dx][y+dy] and !g[x+dx][y+dy]) f(f, x+dx, y+dy);
            }
        }
    };

    for (int i=1024; i<N; ++i) {
        int u, v; cin >> u >> v;
        g[u][v] = 0;
        clear_vis();

        for (int j=0; j<n+1; ++j) if (!vis[j][0] and !g[j][0]) dfs(dfs, j, 0);
        if (dex or top) { cout << u << ',' << v; break; }

        for (int j=0; j<n+1; ++j) if (!vis[n][j] and !g[n][j]) dfs(dfs, n, j);
        if (dex or top) { cout << u << ',' << v; break; }
    }
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();
}

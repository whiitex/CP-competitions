#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;

#define pb push_back
#define f first
#define s second

const int INF = 1e9+9;
vector<vi> coladj(2e5+1, vi());
set<int> allmycolors;

void solve() {
    int n, m; cin >> n >> m;
    map<pii, int> color;
    vector<vi> adj(n+1, vi(0));
    for (int i=0; i<m; ++i) {
        int u, v, c; cin >> u >> v >> c;
        adj[u].pb(v);
        adj[v].pb(u);
        color.insert({{min(u,v), max(u,v)}, c});
        coladj[c].pb(v);
        coladj[c].pb(u);
        allmycolors.insert(c);
    }

    int start, end; cin >> start >> end;

    vector<bool> color_used(2e5+1, false);
    vi dp(n+1, INF); dp[start] = 0;
    queue<int> q; q.push(start);

    vector<bool> visited(n+1, false);
    while (not q.empty()) {
        int node = q.front(); q.pop();

        if (visited[node]) continue;
        visited[node] = true;

        for (int ch: adj[node]) {
            int col = color[{min(node, ch), max(node, ch)}];
            if (color_used[col]) continue;

            color_used[col] = true;
            int mn = INF;
            for (int i: coladj[col]) {
                mn = min(mn, dp[i]);
                if (not visited[i]) q.push(i);
            }
            for (int i: coladj[col]) if (dp[i] > mn) dp[i] = mn + 1;
        }

    }


    cout << dp[end] << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        for (int c: allmycolors) coladj[c] = vi();
        allmycolors = set<int>();
        solve();
    }
}


/*

 void solve() {
    int n, m; cin >> n >> m;
    map<pii, int> color;
    vector<vi> adj(n+1, vector<int>(0));
    for (int i=0; i<m; ++i) {
        int u, v, c; cin >> u >> v >> c;
        adj[u].pb(v);
        adj[v].pb(u);
        color.insert({{min(u,v), max(u,v)}, c});
    }

    int start, end; cin >> start >> end;
    if (start == end) {cout << 0 << '\n'; return;}


    vector<bool> color_used(2e5+1, false);
    vi dp(n+1, INF);
    dp[start] = 0;
    queue<int> q; q.push(start);

    vi upd; map<int, int> visit;

    // DFS to deep the subway line
    auto dfs = [&] (auto self, int node, int col) -> void {
        ++visit[node];
        upd.pb(node);

        for (int ch: adj[node]) {
            int c = color[{min(node, ch), max(node, ch)}];
            if (c == col and not visit[ch]) {
                self(self, ch, col);
                q.push(ch);
            }
        }
    };

    while (not q.empty()) {
        int node = q.front(); q.pop();

        for (int ch: adj[node]) {
            int col = color[{min(node, ch), max(node, ch)}];
            if (color_used[col]) continue;

            color_used[col] = true;
            upd = vi();
            visit = map<int, int>();
            dfs(dfs, node, col);
            int mn = INF; for (int i: upd) mn = min(mn, dp[i]);
            for (int i: upd) if (dp[i] > mn) dp[i] = mn + 1;
        }

    }


    cout << dp[end] << '\n';

}

 */
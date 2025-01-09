#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;

#define pb push_back
const int INF = 1e9;

void solve() {
    int n; cin >> n;
    vector adj(n+1, vi());
    for (int i=2; i<=n; ++i) {
        int a; cin >> a;
        adj[a].pb(i);
    }
    string s; cin >> s; s = " " + s;

    vi dep(n+1);
    auto dfs = [&](auto f, int u) -> void {
        for (int v: adj[u]) {
            dep[v] = dep[u] + 1;
            f(f, v);
        }
    }; dfs(dfs, 1);

    vector dp(n+1, vi(3, INF));
    priority_queue<pii> pq;
    for (int i=1; i<=n; ++i) {
        if (adj[i].size() > 0) pq.push({dep[i], i});
        else {
            if (s[i] == 'C') dp[i] = {0,0,0};
            dp[i][s[i] == 'P' ? 0 : s[i] == 'S' ? 1 : 2] = 0;
            dp[i][2] = 1;
        }
    }
    while (!pq.empty()) {
        auto [_, u] = pq.top(); pq.pop();

        if (s[u] == 'P') {
            int in = 0;
            for (int v: adj[u]) in += min(dp[v][0], dp[v][2]);
            dp[u][0] = in;
            dp[u][2] = in + 1;

        } else if (s[u] == 'S') {
            int in = 0;
            for (int v: adj[u]) in += min(dp[v][1], dp[v][2]);
            dp[u][1] = in;
            dp[u][2] = in + 1;

        } else { // s[u] == 'C'
            dp[u] = {0, 0, 0};
            for (int v: adj[u]) {
                dp[u][0] += min({dp[v][1]+1, dp[v][0], dp[v][2]});
                dp[u][1] += min({dp[v][0]+1, dp[v][1], dp[v][2]});
                dp[u][2] += dp[v][2];
            }

            dp[u][2] = min({dp[u][2], dp[u][0] + 1, dp[u][1] + 1});
        }

    }

    int ans = min({dp[1][0], dp[1][1], dp[1][2]});
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;


#define pb push_back
#define st first
#define nd second

const int MAXN = 5e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 1e18;

void solve() {
    int n; cin >> n;
    vector adj(n+1, vi());
    for (int i=1; i<n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    if (n == 2) { cout << 0 << '\n'; return; }

    vi dep(n+1, 0), par(n+1, 0);
    set<int> leaves, pre_leaves;
    {
        auto dfs = [&] (auto f, int u) -> void {
            if (adj[u].size() == 1) leaves.insert(u); // leaves
            for (int v: adj[u]) if (v != par[u]) {
                if (adj[v].size() == 1) pre_leaves.insert(u); // pre-leaves
                par[v] = u; dep[v] = dep[u] + 1;
                f(f, v);
            }
        };
        int x = 1;
        while (adj[x].size() == 1) ++x;
        dfs(dfs, x);
    }

    int ans = 0, l_cnt = (int)leaves.size(), prel_cnt = (int)pre_leaves.size();
    for (int u=1; u<=n; ++u) if (pre_leaves.contains(u)) {
        int cnt = 0;
        for (int v: adj[u]) if (!leaves.contains(v)) ++cnt;
        ans += (cnt - 1) * (n - l_cnt - prel_cnt);
    }

    ans += l_cnt * (n - l_cnt);
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

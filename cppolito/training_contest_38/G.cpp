#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;
#define pb push_back

void solve() {
    string s; cin >> s;
    int n = (int)s.size();
    
    vector adj(n+1, vi());
    int index = 1, p = 0;
    for (char c: s) {
        if (c == ')') ++p;
        else adj[p].pb(index++);
    }

    auto dfs = [&adj] (auto f, int u, int p) -> void {
        if (u) cout << '(';
        if (!adj[u].empty()) {
            reverse(adj[u].begin(), adj[u].end());
            for (int v: adj[u]) if (v != p) f(f, v, u);
        }
        if (u) cout << ')';
    };

    dfs(dfs, 0, -1);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();
}
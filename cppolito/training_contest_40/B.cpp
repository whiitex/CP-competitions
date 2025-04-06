#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;

#define pb push_back

void solve() {
    int n, k; cin >> n >> k;
    vector adj(n+1, vi());
    map<pii, int> mp;
    for (int i=1; i<n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].pb(v); adj[v].pb(u);
        mp[{u, v}] = mp[{v, u}] = i-1;
    }

    vi ck(n); for (int i=1; i<=n; ++i) {
        ck[i-1] = (int)adj[i].size();
    } sort(ck.begin(), ck.end(), greater<>());

    int colors = n-1;
    for (int i=0, p=n; i<=k; ++i) {
        if (ck[i] < p) {
            p = colors = ck[i];
        }
    }

    vi ans(n-1);
    auto dfs = [&] (auto f, int u, int p, int c) -> void {
        int col = 1;
        for (int v: adj[u]) if (v != p) {
            if (adj[u].size() <= colors) {
                if (col == c) ++col;
                ans[mp[{u, v}]] = col++;
            } else ans[mp[{u, v}]] = col;

            f(f, v, u, ans[mp[{u, v}]]);
        }
    }; dfs(dfs, 1, -1, -1);

    cout << colors << '\n';
    for (int i: ans) cout << i << ' ';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();
}

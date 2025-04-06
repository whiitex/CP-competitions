#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;

#define pb push_back

const int MAXN = 1e5+10;

void solve() {
    int n, q; cin >> n >> q;
    vi a(n+1); for (int i=1; i<=n; ++i) cin >> a[i];

    vi dep(n+1), par(n+1);
    vector adj(n+1, vi());
    for (int u=2; u<=n; ++u) {
        cin >> par[u];
        adj[par[u]].pb(u);
    }

    par[1] = -1;
    auto dfs = [&] (auto dfs, int u) -> void {
        for (int v: adj[u]) {
            dep[v] = dep[u] + 1;
            dfs(dfs, v);
        }
    }; dfs(dfs, 1);

    vector mpdep(MAXN, vi());
    for (int i=1; i<=n; ++i) {
        mpdep[dep[i]].pb(i);
    }

    map<pii,int> mp;
    vi done(n+1);

    auto getValue = [&] (int u, int v) -> int {
        int value = 0;
        while (u != -1) {
            if (done[dep[u]]) return mp[{u,v}] + value;
            value += a[u] * a[v];
            u = par[u], v = par[v];
        } return value;
    };

    for (int d=250; d<n+1; d+=250) {
        if (mpdep[d].empty()) break;

        for (int u: mpdep[d]) for (int v: mpdep[d]) if (u <= v) {
            mp[{u,v}] = mp[{v, u}] = getValue(u, v);
        }
        done[d] = 1;
    }

    while (q--) {
        int u, v; cin >> u >> v;
        if (u > v) swap(u, v);
        cout << getValue(u, v) << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; // cin >> t;
    while (t--) solve();
}



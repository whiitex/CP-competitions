#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;

#define pb push_back

const int MAXN = 1e5 + 5;

struct DSU {
    explicit DSU(int n): Par(n), Sz(n, 1) {
        iota(Par.begin(), Par.end(), 0);
    }

    int find(int node) {
        if (Par[node] == node) return node;
        return Par[node] = find(Par[node]);
    }

    void merge(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return;
        if (Sz[a] < Sz[b]) swap(a, b);
        Par[b] = a; Sz[a] += Sz[b];
    }
private: vector<int> Par, Sz;
};

void solve() {
    int n, m; cin >> n >> m;
    vector haszero(n, false);
    vector<array<int,3>> edges;
    for (int i=0, u, v, w; i<m; ++i) {
        cin >> u >> v >> w; --u; --v;
        if (!(w & 1)) haszero[u] = haszero[v] = true;
        edges.pb({u, v, w});
    }

    vector dsu(64, DSU(MAXN));

    // only 1 bit
    for (int bit=0; bit<30; ++bit) {
        for (auto [u, v, w]: edges) {
            if (w & (1 << bit)) dsu[bit].merge(u, v);
        }
    }

    // bit 0 and ith
    for (int bit=1; bit<30; ++bit) {
        for (auto [u, v, w]: edges) {
            if ((w & 1) and (w & (1 << bit))) dsu[31+bit].merge(u, v);
        }
    }

    vector outone(32, vi(n, false));
    for (int u=0; u<n; ++u) if (haszero[u]) {
        for (int bit=1; bit<30; ++bit) {
            outone[bit][dsu[31+bit].find(u)] = true;
        }
    }

    int q; cin >> q; while (q--) {
        int u, v; cin >> u >> v; --u; --v;

        int done = 0;
        for (int bit=0; bit<30 and !done; ++bit) {
            if (dsu[bit].find(u) == dsu[bit].find(v)) {
                cout << 0 << '\n';
                done = 1;
            }
        }

        for (int bit=1; bit<30 and !done; ++bit) {
            if (outone[bit][dsu[31+bit].find(u)]) {
                cout << 1 << '\n';
                done = 1;
            }
        }

        if (!done) cout << 2 << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; // cin >> t;
    while (t--) solve();
}

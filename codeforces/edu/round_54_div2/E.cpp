#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

#define pb push_back

template<typename T> struct SegmentTree {
    int n;
    vector<T> tree, lazy;

    SegmentTree (vector<T> vec) : n((int)vec.size()), tree(2*n), lazy(2*n, 0)  { // n is a power of 2
        for (int i=0; i<n; ++i) tree[n+i] = vec[i];
        for (int i=n-1; i>=1; --i) tree[i] = tree[i*2] + tree[i*2+1];
    }

    T query(int pos, int node_l, int node_r, int query_l, int query_r) {
        push_lazy(pos, node_l, node_r);

        if (node_r <= query_r && node_l >= query_l) return tree[pos];
        if (node_l > query_r || node_r < query_l) return 0;

        int max_l = (node_l + node_r) >> 1;
        T q1 = query(pos<<1, node_l, max_l, query_l, query_r);
        T q2 = query((pos<<1)+1, max_l+1, node_r, query_l, query_r);
        return q1 + q2;
    }

    void update_range(int pos, int node_l, int node_r, int change_l, int change_r, int v) {
        push_lazy(pos, node_l, node_r);

        if (node_r <= change_r && node_l >= change_l) {
            tree[pos] += (node_r - node_l + 1) * v;
            lazy[pos] += v;
            push_lazy(pos, node_l, node_r);
            return;
        }

        if (node_l > change_r or node_r < change_l) return;

        int max_l = (node_l + node_r) >> 1;
        update_range(pos<<1, node_l, max_l, change_l, change_r, v);
        update_range((pos<<1)+1, max_l+1, node_r, change_l, change_r, v);
        tree[pos] = tree[pos<<1] + tree[(pos<<1)+1];
    }


    void push_lazy(int pos, int node_l, int node_r) {
        if (lazy[pos] and pos < n) {
            tree[pos*2] += (node_r - node_l + 1) / 2 * lazy[pos];
            tree[pos*2 + 1] += (node_r - node_l + 1) / 2 * lazy[pos];

            if (pos*2 < n) {
                lazy[pos*2] += lazy[pos];
                lazy[pos*2+1] += lazy[pos];
            }
        } lazy[pos] = 0;
    }
};

void solve() {
    int n; cin >> n;
    vector adj(n+1, vi());
    for (int i=1; i<n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vector queries(n+1, vpii());
    int q; cin >> q; while (q--) {
        int v, d, x; cin >> v >> d >> x;
        queries[v].pb({d, x});
    }

    int N = n;
    while (__builtin_popcount(n) != 1) ++n;
    vi for_seg(n);
    SegmentTree<int> stree(for_seg);

    vi dep(n+1), ans(n+1);
    auto dfs = [&] (auto f, int u, int p) -> void {
        for (auto [d, x]: queries[u]) {
            stree.update_range(1, 0, n-1, dep[u], min(n-1, dep[u] + d), x);
        }

        ans[u] = stree.query(1, 0, n-1, dep[u], dep[u]);
        for (int v: adj[u]) if (v != p) {
            dep[v] = dep[u] + 1;
            f(f, v, u);
        }

        for (auto [d, x]: queries[u]) {
            stree.update_range(1, 0, n-1, dep[u], min(n-1, dep[u] + d), -x);
        }
    }; dfs(dfs, 1, 0);

    for (int i=1; i<=N; ++i) cout << ans[i] << ' ';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();
}

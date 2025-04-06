#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

#define pb push_back

template<typename T> struct SegmentTree {
    int n, neutral = 0;
    vector<T> tree, lazy;

    SegmentTree (vector<T> vec) : n((int)vec.size()), tree(2*n), lazy(2*n, 0)  { // n is a power of 2
        for (int i=0; i<n; ++i) tree[n+i] = vec[i];
        for (int i=n-1; i>=1; --i) tree[i] = merge(tree[i*2], tree[i*2+1]);
    }

    T query(int l, int r) { return query(1, 0, n-1, l, r); } // l/r is 0-indexed
    void update_range(int l, int r, int v) { update_range(1, 0, n-1, l, r, v); } // l/r is 0-indexed
    void update_single(int pos, int v) { update_range(1, 0, n-1, pos, pos, v); } // pos is 0-indexed

    T query(int pos, int node_l, int node_r, int query_l, int query_r) {
        push_lazy(pos, node_l, node_r);

        if (node_r <= query_r && node_l >= query_l) return tree[pos];
        if (node_l > query_r || node_r < query_l) return neutral; // neutral element

        int max_l = (node_l + node_r) >> 1;
        T q1 = query(pos<<1, node_l, max_l, query_l, query_r);
        T q2 = query((pos<<1)+1, max_l+1, node_r, query_l, query_r);
        return merge(q1, q2); // operation
    }

    void update_range(int pos, int node_l, int node_r, int change_l, int change_r, int v) { // change_l/r is 0-indexed
        push_lazy(pos, node_l, node_r);

        if (node_r <= change_r && node_l >= change_l) {
            tree[pos] += v; // lazy operation (range update)
            lazy[pos] += v; // lazy update
            push_lazy(pos, node_l, node_r);
            return;
        }

        if (node_l > change_r or node_r < change_l) return;

        int max_l = (node_l + node_r) >> 1;
        update_range(pos<<1, node_l, max_l, change_l, change_r, v);
        update_range((pos<<1)+1, max_l+1, node_r, change_l, change_r, v);
        tree[pos] = merge(tree[pos<<1], tree[(pos<<1)+1]);
    }

    void push_lazy(int pos, int node_l, int node_r) {
        if (lazy[pos] and pos < n) {
            tree[pos*2] += lazy[pos]; // lazy operation (range update)
            tree[pos*2 + 1] += lazy[pos]; // lazy operation (range update)

            if (pos*2 < n) {
                lazy[pos*2] += lazy[pos]; // lazy below update
                lazy[pos*2+1] += lazy[pos]; // lazy below update
            }
        } lazy[pos] = neutral; // neutral element (on lazy)
    }

    T merge(T a, T b) { // complete (function)
        return max(a, b);
    }
};

void solve() {
    int n; cin >> n;
    vector adj(n, vi());
    for (int i=1; i<n; ++i) {
        int u, v; cin >> u >> v; --u; --v;
        adj[u].pb(v); adj[v].pb(u);
    }

    vi depth(n), st(n), en(n); int time = -1;
    auto dfs0 = [&] (auto f, int u, int p, int dep) -> void {
        st[u] = ++time;
        depth[st[u]] = dep;
        for (int v: adj[u]) if (v != p) f(f, v, u, dep+1);
        en[u] = time;
    }; dfs0(dfs0, 0, -1, 0);

    int N = n;
    while (__builtin_popcount(N) != 1) {
        ++N; depth.pb(0);
    }
    SegmentTree sgt(depth);

    vector queries(n, vpii());
    int q; cin >> q; for (int i=0; i<q; ++i) {
        int v, k; cin >> v >> k; --v;
        queries[v].pb({k, i});
    }

    vi ans(q), path;
    auto dfs = [&] (auto f, int u, int p) -> void {
        path.pb(u);
        for (auto [k, i]: queries[u]) {
            int v = path[max(0ll, (int)path.size()-1-k)];
            ans[i] = sgt.query(1, 0, N-1, st[v], en[v]);
        }

        for (int v: adj[u]) if (v != p) {
            sgt.update_range(st[v], en[v], -1);
            sgt.update_range(0, st[v]-1, 1);
            if (en[v] != N-1) sgt.update_range(en[v]+1, N-1, 1);
            f(f, v, u);
            sgt.update_range(st[v], en[v], 1);
            sgt.update_range(0, st[v]-1, -1);
            if (en[v] != N-1) sgt.update_range(en[v]+1, N-1, -1);
        }
        path.pop_back();
    };

    dfs(dfs, 0, -1);

    for (int i: ans) cout << i << ' '; cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

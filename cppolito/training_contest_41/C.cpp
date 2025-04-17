#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

#define st first
#define nd second

template<typename T> struct SegmentTree {
    T neutral = 0; // CHANGE (neutral element)
    int n;
    vector<T> tree;

    SegmentTree (vector<T> vec) : n((int)vec.size()), tree(2*n) { // n is a power of 2
        for (int i=0; i<n; ++i) tree[n+i] = vec[i];
        for (int i=n-1; i>=1; --i) tree[i] = merge(tree[i*2], tree[i*2+1]);
    }

    T query(int l, int r) { return query(1, 0, n-1, l, r); } // l/r is 0-indexed
    void update(int pos, int v) { update(1, 0, n-1, pos, v); } // pos is 0-indexed

    T query(int pos, int node_l, int node_r, int query_l, int query_r) { // query 0-indexed

        if (node_r <= query_r && node_l >= query_l) return tree[pos];
        if (node_l > query_r || node_r < query_l) return neutral;

        int max_l = (node_l + node_r) >> 1;
        T q1 = query(pos<<1, node_l, max_l, query_l, query_r);
        T q2 = query((pos<<1)+1, max_l+1, node_r, query_l, query_r);
        return merge(q1, q2); // operation
    }

    void update(int pos, int node_l, int node_r, int change_pos, int v) {
        if (change_pos == node_l && change_pos == node_r) {
            tree[pos] = v; return;
        }

        if (change_pos > node_r || change_pos < node_l) return;

        int max_l = (node_l + node_r) >> 1;
        update(pos<<1, node_l, max_l, change_pos, v);
        update((pos<<1)+1, max_l+1, node_r, change_pos, v);
        tree[pos] = merge(tree[pos<<1], tree[(pos<<1)+1]); // operation
    }

    T merge(T a, T b) { // complete (function)
        return a + b;
    }
};

void solve() {
    int n; cin >> n;
    vi a(n); for (int &i: a) cin >> i;

    vpii arcs;
    for (int i=0; i<n; ++i) {
        arcs.emplace_back(i+1, a[i] >= i+1 ? a[i] : a[i] + n);
        if (a[i] >= i+1) arcs.emplace_back(i+1 + n, a[i] + n);
    }

    sort(arcs.begin(), arcs.end(), [](pii a, pii b) {
        return a.st > b.st;
    });

    vi base(2*n+2, 1); int N = 2*n+2;
    while (__builtin_popcount(N) != 1) {
        base.push_back(1); ++N;
    }

    for (auto [l, r]: arcs) if (l > n) base[r] = 0;
    SegmentTree sgt(base);

    vi ans(n+1);
    for (auto [l, r]: arcs) if (l <= n) {
        int pos = r > n ? r - n : r;
        sgt.update(r, 0);
        ans[pos] = sgt.query(l, r);
    }

    for (int i=1; i<=n; ++i) cout << ans[i] << ' '; cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

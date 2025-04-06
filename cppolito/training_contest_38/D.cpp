#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

const int INF = 1e9+1;

template<typename T> struct SegmentTree {
    int n;
    vector<T> tree;

    explicit SegmentTree (vector<T> vec) : n((int)vec.size()), tree(2*n)  { // n is a power of 2
        for (int i=0; i<n; ++i) tree[n+i] = vec[i];
        for (int i=n-1; i>=1; --i) tree[i] = tree[i*2] + tree[i*2+1];
    }

    T query(int pos, int node_l, int node_r, int query_l, int query_r) {

        if (node_r <= query_r && node_l >= query_l) return tree[pos];
        if (node_l > query_r || node_r < query_l) return 0;

        int max_l = (node_l + node_r) >> 1;
        return query(pos<<1, node_l, max_l, query_l, query_r) +
            query((pos<<1)+1, max_l+1, node_r, query_l, query_r);
    }

    void update(int pos, int node_l, int node_r, int change_pos, int v) {
        if (change_pos == node_l && change_pos == node_r) {
            tree[pos] = v; return;
        }

        if (change_pos > node_r || change_pos < node_l) return;

        int max_l = (node_l + node_r) >> 1;
        update(pos<<1, node_l, max_l, change_pos, v);
        update((pos<<1)+1, max_l+1, node_r, change_pos, v);
        tree[pos] = tree[pos<<1] + tree[(pos<<1)+1];
    }
};

void solve() {
    int n, q; cin >> n >> q;
    vi a(n); for (int &i: a) cin >> i;

    int N = n;
    set<int> reset = {0, n};
    for (int i=1; i<n; ++i) if (a[i] < a[i-1]) reset.insert(i);

    while (__builtin_popcount(n) != 1) ++n;
    SegmentTree<int> segtree(vi(n, 0));
    for (int r: reset) if (r != *reset.rbegin()) {
        int nxt = *reset.upper_bound(r);
        int d = nxt - r;
        int value = d * (d+1) / 2;
        segtree.update(1, 0, n-1, r, value);
    }

    while (q--) {
        int op; cin >> op;

        if (op == 1) { // opearation 1
            int x, y; cin >> x >> y; --x;

            int lx = x, rx = x+1;
            if (x < N-1) {
                if (y <= a[x+1]) {
                    reset.erase(x); reset.erase(x+1);
                    segtree.update(1, 0, n-1, x+1, 0);
                    segtree.update(1, 0, n-1, x, 0);
                    rx = *reset.lower_bound(x);
                } else {
                    reset.insert(x+1);
                    int d = (*reset.upper_bound(x+1)) - (x+1);
                    int value = d * (d+1) / 2;
                    segtree.update(1, 0, n-1, x+1, value);
                }
            }

            if (x > 0) {
                if (y >= a[x-1]) {
                    reset.erase(x);
                    segtree.update(1, 0, n-1, x, 0);
                    lx = *(--reset.lower_bound(x));
                } else {
                    reset.insert(x);
                    int prev = *(--reset.lower_bound(x));
                    int d = x - prev;
                    int value = d * (d+1) / 2;
                    segtree.update(1, 0, n-1, prev, value);
                }
            }

            reset.insert(lx);
            int d = rx - lx;
            int value = d * (d+1) / 2;
            segtree.update(1, 0, n-1, lx, value);
            a[x] = y;
        }

        if (op == 2) { // opearation 2
            int l, r; cin >> l >> r; --l, --r;

            int lx = *reset.lower_bound(l);
            int rx = *(--reset.upper_bound(r)); --rx;

            if (lx > r or rx < l) {
                int d = r-l+1;
                int value = d * (d+1) / 2;
                cout << value << '\n';
            } else {
                int ans = 0;
                int d1 =  lx - l;
                ans += d1 * (d1+1) / 2;
                int d2 = r - rx;
                ans += d2 * (d2+1) / 2;

                if (lx <= rx) ans += segtree.query(1, 0, n-1, lx, rx);
                cout << ans << '\n';
            }
        }
    }

}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();
}

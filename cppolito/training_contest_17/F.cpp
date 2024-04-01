#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

#define pb push_back
#define f first
#define s second


const int INF = 1e9+1;

void out(int x, int y) {
    cout << x << ' ' << y << '\n';
}

struct SegmentTree {
    vector<array<int,4>> tree;

    SegmentTree (vector<array<int,4>> vec, int n) { // n is a power of 2
        tree.resize(2*n);

        for (int i=0; i<n; ++i)
            tree[n+i] = vec[i];

        for (int i=n-1; i>=1; --i) {
            tree[i][0] = max(tree[i * 2][0], tree[i * 2 + 1][0]);
            tree[i][1] = max(tree[i * 2][1], tree[i * 2 + 1][1]);
            tree[i][2] = min(tree[i * 2][2], tree[i * 2 + 1][2]);
            tree[i][3] = min(tree[i * 2][3], tree[i * 2 + 1][3]);
        }
    }

    array<int,4> query(int pos, int node_l, int node_r, int query_l, int query_r) {

        if (node_r <= query_r && node_l >= query_l)
            return tree[pos];

        if (node_l > query_r || node_r < query_l)
            return {-INF, -INF, INF, INF};

        int max_l = (node_l + node_r) >> 1;
        array<int,4> a = query(pos<<1, node_l, max_l, query_l, query_r);
        array<int,4> b = query((pos<<1)+1, max_l+1, node_r, query_l, query_r);
        return {max(a[0], b[0]) , max(a[1], b[1]) , min(a[2], b[2]) , min(a[3], b[3])};
    }

    void update(int pos, int node_l, int node_r, int change_pos, array<int,4> v) {
        if (change_pos == node_l && change_pos == node_r) {
            tree[pos] = v;
            return;
        }

        if (change_pos > node_r || change_pos < node_l)
            return;

        int max_l = (node_l + node_r) >> 1;
        update(pos<<1, node_l, max_l, change_pos, v);
        update((pos<<1)+1, max_l+1, node_r, change_pos, v);

        tree[pos][0] = max(tree[pos * 2][0], tree[pos * 2 + 1][0]);
        tree[pos][1] = max(tree[pos * 2][1], tree[pos * 2 + 1][1]);
        tree[pos][2] = min(tree[pos * 2][2], tree[pos * 2 + 1][2]);
        tree[pos][3] = min(tree[pos * 2][3], tree[pos * 2 + 1][3]);
    }

};

void solve() {
    int n; cin >> n;
    vector<array<int,4>> vec(n);
    for (int i=0; i<n; ++i) {
        cin >> vec[i][0];
        cin >> vec[i][1];
        cin >> vec[i][2];
        cin >> vec[i][3];
    }

    while (__builtin_popcount(n) != 1) {
        ++n;
        vec.pb({-INF, -INF, INF, INF});
    }

    SegmentTree seg_tree(vec, n);

    auto resp = seg_tree.query(1, 0, n-1, 0, n-1);
    if (resp[0] <= resp[2] and resp[1] <= resp[3]) {
        out(resp[0], resp[1]);
        return;
    }

    for (int i=0; i<n; ++i) {
        auto save = vec[i];

        seg_tree.update(1, 0, n-1, i, {-INF, -INF, INF, INF});
        resp = seg_tree.query(1,0,n-1,0,n-1);
        if (resp[0] <= resp[2] and resp[1] <= resp[3]) {
            out(resp[0], resp[1]);
            return;
        }
        seg_tree.update(1,0,n-1, i, save);
    }


}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}

/* Not working - WA
 *
void out(int x, int y) {
    cout << x << ' ' << y << '\n';
}

void solve() {
    int n; cin >> n;
    vpii vx, vy;
    vector<array<int,4>> rects(n);
    for (int i=0; i<n; ++i) {
        int x, y; cin >> x >> y;
        array<int,4> rect{};
        vx.emplace_back(x,0);
        vy.emplace_back(y,0);
        rect[0] = x; rect[1] = y;
        cin >> x >> y;
        vx.emplace_back(x,1);
        vy.emplace_back(y,1);
        rect[2] = x; rect[3] = y;
        rects[i] = rect;
    }

    std::sort(vx.begin(), vx.end());
    std::sort(vy.begin(), vy.end());

    auto f = [&n] (vpii& vec, vi& l, vi& r) -> void {

        int count = 0;
        for (pii p: vec) {
            if (p.s == 0) {
                ++count;
                if (count >= n-1) l.pb(p.f);
            }
            else {
                --count;
                if (count >= n-2) r.pb(p.f);
            }

        }
    };

    vi lx, rx, ly, ry;
    f(vx, lx, rx);
    f(vy, ly, ry);

    auto check = [&rects, &n] (int x, int y) -> bool {
        int count = 0;
        for (auto r: rects)
            if (x >= r[0] and y >= r[1])
                ++count;

        return count >= n-1;
    };

    bool flag = true;
    for (int i=0; i<int(lx.size()) and flag; ++i) {
        for (int j=0; j<int(ly.size()) and flag; ++j) {
            if (check(lx[i], ly[j])) {
                out(lx[i], ly[j]);
                flag = false;
            } else if (check(lx[i], ry[j])) {
                out(lx[i], ry[j]);
                flag = false;
            } else if (check(rx[i], ly[j])) {
                out(rx[i], ly[j]);
                flag = false;
            } else if (check(rx[i], ry[j])) {
                out(rx[i], ry[j]);
                flag = false;
            }
        }
    }

}
 */
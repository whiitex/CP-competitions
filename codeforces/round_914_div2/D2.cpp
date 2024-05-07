#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

#define f first
#define s second
#define pb push_back

const int MAXN = 1e5;
const int INF = 1e9;

template<typename T> struct SegmentTree {
    vector<T> tree;
    string func;

    SegmentTree (vector<T> vec, int n, string function) { // n is a power of 2
        func = function;
        tree.resize(2 * n);

        for (int i = 0; i < n; ++i)
            tree[n + i] = vec[i];

        for (int i = n - 1; i >= 1; --i) {
            if (function == "min")
                tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
            if (function == "max")
                tree[i] = max(tree[i * 2], tree[i * 2 + 1]);
        }
    }

    T query(int pos, int node_l, int node_r, int query_l, int query_r) {

        if (node_r <= query_r && node_l >= query_l)
            return tree[pos];

        if (node_l > query_r || node_r < query_l)
            return func == "max" ? -1 : INF;

        int max_l = (node_l + node_r) >> 1;
        if (func == "min")
            return min(query(pos<<1, node_l, max_l, query_l, query_r),
                   query((pos<<1)+1, max_l+1, node_r, query_l, query_r));
        if (func == "max")
            return max(query(pos<<1, node_l, max_l, query_l, query_r),
                query((pos<<1)+1, max_l+1, node_r, query_l, query_r));
    }

};

string solve() {
    int n; cin >> n;
    vi a(n); for (int &i: a) cin >> i;
    vi b(n); for (int &i: b) cin >> i;

    bool ok = true;
    for (int i=0; i<n; ++i) if (b[i] < a[i]) ok = false;

    if (!ok) {return "No";}

    vpii close(n);
    { // left
        vi found(n+1, INF);
        for (int i=0; i<n; ++i) {
            close[i].f = found[b[i]];
            found[a[i]] = i;
        }
    }

    { // right
        vi found(n+1, INF);
        for (int i=n-1; i>=0; --i) {
            close[i].s = found[b[i]];
            found[a[i]] = i;
        }
    }

    vector<bool> vecok(n, false);
    for (int i=0; i<n; ++i) if (a[i] == b[i]) vecok[i] = true;

    int N = n;
    while (__builtin_popcount(N) != 1) {
        ++N;
        b.pb(INF);
        a.pb(-1);
    }

    SegmentTree<int> segTreeA(a, N, "max");
    SegmentTree<int> segTreeB(b, N, "min");

    // left
    for (int i=0; i<n; ++i) {
        if (vecok[i]) continue;

        bool flag = true;

        int j = close[i].f;
        if (j == INF) continue;

        int minB = segTreeB.query(1, 0, N-1, j, i);
        int maxA = segTreeA.query(1, 0, N-1, j, i);

        if (minB < b[i] or maxA > b[i]) flag = false;

        vecok[i] = flag;
    }

    // right
    for (int i=n-1; i>=0; --i) {
        if (vecok[i]) continue;

        bool flag = true;

        int j = close[i].s;
        if (j == INF) continue;

        int minB = segTreeB.query(1, 0, N-1, i, j);
        int maxA = segTreeA.query(1, 0, N-1, i, j);

        if (minB < b[i] or maxA > b[i]) flag = false;

        vecok[i] = flag;
    }

    bool ans = true;
    for (bool i: vecok) ans &= i;

    return (ans ? "Yes" : "No");
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) cout << solve() << '\n';
}

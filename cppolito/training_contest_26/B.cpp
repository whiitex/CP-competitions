#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

template<typename T> struct SegmentTree {
    vector<T> tree;

    SegmentTree (vector<T> vec, int n) { // n is a power of 2
        tree.resize(2*n);

        for (int i=0; i<n; ++i)
            tree[n+i] = vec[i];

        for (int i=n-1; i>=1; --i)
            tree[i] = max(tree[i*2], tree[i*2+1]);
    }

    T query(int pos, int node_l, int node_r, int query_l, int query_r) {

        if (node_r <= query_r && node_l >= query_l)
            return tree[pos];

        if (node_l > query_r || node_r < query_l)
            return -1;

        int max_l = (node_l + node_r) >> 1;
        return max(query(pos<<1, node_l, max_l, query_l, query_r),
                   query((pos<<1)+1, max_l+1, node_r, query_l, query_r));
    }
};

void solve() {
    string s; cin >> s;
    s = ' ' + s;
    int n = s.size();

    vi pref(n, 0);
    for (int i=1; i<n; ++i) {
        int add = s[i] == '(' ? 1 : -1;
        pref[i] = pref[i-1] + add;
    }

    int N = n;
    while (__builtin_popcount(N) != 1) {
        ++N;
        pref.push_back(0);
    }

    SegmentTree<int> segmentTree(pref, N);

    vi dp(n+2, 0);
    unordered_map<int,int> mp;

    for (int i=1; i<n; ++i) {

        if (mp[pref[i]] != 0) {
            int l = mp[pref[i]] + 1;
            int mx = segmentTree.query(1, 0, N-1, l, i);
            if (mx - pref[l-1] <= pref[l-1]) {
                dp[i] = 1 + dp[l-1];
            }
        }

        mp[pref[i]] = i;
    }

    int ans = 0;
    for (int a: dp) ans += a;
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

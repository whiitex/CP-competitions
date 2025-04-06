#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    set<int> a; for (int i=0; i<k; ++i) {
        int x; cin >> x; a.insert(x);
    }

    if (k == n) { cout << "-1\n"; return; }
    if (m > n*(n-1)/2 - k + 1) { cout << "-1\n"; return; }

    int x = *a.begin(), c = 1;
    while (a.contains(c)) ++c;

    set<pair<int,int>> ans;
    for (int i=1; i<=n; ++i) if (i != c) {
        ans.insert({min(i,c), max(i,c)});
    }

    int size = ans.size();
    for (int u=1; u<=n and size < m; ++u) for (int v=1; v<=n and size < m; ++v) {
        if (u == v) continue;

        if (u == x and a.contains(v)) continue;
        if (v == x and a.contains(u)) continue;

        ans.insert({min(u,v), max(u,v)});
        size = ans.size();
    }

    for (auto [o, p]: ans) cout << o << ' ' << p << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();
}

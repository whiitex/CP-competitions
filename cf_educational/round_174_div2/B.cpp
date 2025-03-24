#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

#define pb push_back
#define st first
#define nd second

void solve() {
    int n, m; cin >> n >> m;
    vector<vpii> cols(n*m+1);
    map<pii, int> col;
    for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) {
        int x; cin >> x;
        cols[x].pb({i, j});
        col[{i, j}] = x;
    }

    vi cost(n*m+1, 0);
    for (int c=1; c<=n*m; ++c) if (!cols[c].empty()) {
        int ok = 1;
        for (pii &p: cols[c]) {
            for (int dx: {1, 0, -1}) for (int dy: {-1, 0, 1}) if (!dx xor !dy) {
                if (col[{p.st + dx, p.nd + dy}] == c) ok = 0;
            }

            if (!ok) break;
        }

        cost[c] = ok ? 1 : 2;
    }

    int ans = 0, mx = -1;
    for (int i: cost) {
        ans += i; mx = max(mx, i);
    }

    cout << ans - mx << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

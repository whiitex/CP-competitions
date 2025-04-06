#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;
#define pb push_back

const int MAXN = 2e7 + 5;

vi newans(MAXN);

void solve() {
    int n, m; cin >> n >> m;
    vector between(n+1, vi());
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        between[b].pb(a);
    }

    vector<vi> freq(n+10, vi());
    vi f(n+10, 0); f[1] = 1;

    { // check infinity
        queue<int> q; q.push(1);
        vi vis(n+1); vis[1] = 1;

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v: between[u]) if (!vis[v]) {
                vis[v] = 1;
                q.push(v);
                f[v] = f[u] + 1;
                freq[f[v]].pb(v);
            }
        }

        int cnt = 0;
        for (int i=1; i<=n; ++i) cnt += vis[i];
        if (cnt < n) { cout << "INFINITE\n"; return; }
    }


    vi ans;

    for (int fr=n+1; fr>0; --fr) {
        for (int i: freq[fr]) ans.pb(i);
    }

    ans.pb(1);

    for (int mnfreq=2; mnfreq<=n+1; ++mnfreq) {
        for (int fr=n+1; fr>=mnfreq; --fr) {
            for (int i: freq[fr]) ans.pb(i);
        }
    }

    cout << "FINITE\n" << ans.size() << '\n';
    for (int i: ans) cout << i << ' ';
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

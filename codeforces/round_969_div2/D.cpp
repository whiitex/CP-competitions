#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

#define pb push_back

void solve() {
    int n; cin >> n;
    vector<vi> adj(n+1, vi());

    for (int i=0; i<n-1; ++i) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    string s; cin >> s; s = ' ' + s;

    int leav1 = 0, leav0 = 0, leavfree = 0, other = 0;
    for (int i=2; i<=n; ++i) {
        if (adj[i].size() == 1) {
            if (s[i] == '1') ++leav1;
            if (s[i] == '0') ++leav0;
            if (s[i] == '?') ++leavfree;
        } else if (s[i] == '?') {
            ++other;
        }
    }

    int ans;
    if (s[1] == '1') {
        ans = leav0 + (leavfree + 1) / 2;
    } else if (s[1] == '0') {
        ans = leav1 + (leavfree + 1) / 2;
    } else if (leav0 != leav1) {
        ans = max(leav0 + (leavfree) / 2, leav1 + (leavfree) / 2);
    } else {
        if (other % 2) {
            ans = max(leav0 + (leavfree+1) / 2, leav1 + (leavfree+1) / 2);
        } else {
            ans = max(leav0 + (leavfree) / 2, leav1 + (leavfree) / 2);
        }
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
    int m, n, v; cin >> n >> m >> v;
    vi vec(n); for (int &i: vec) cin >> i;

    vi pref(vec); for (int i=1; i<n; ++i) pref[i] += pref[i-1];
    vi fst(m, -1), gst(m, -1);
    int j=0, sm = 0;
    for (int i=0; i<n; ++i) {
        if (j == m) break;

        sm += vec[i];
        if (sm >= v) {
            fst[j] = i;
            ++j; sm = 0;
        }
    }

    j=0, sm = 0;
    for (int i=n-1; i>=0; --i) {
        if (j == m) break;

        sm += vec[i];
        if (sm >= v) {
            gst[j] = i;
            ++j; sm = 0;
        }
    }

    if (fst[m-1] == -1 and gst[m-1] == -1) {cout << -1 << '\n'; return; }

    int ans = 0;
    ans = pref[n-1] - pref[fst[m-1]];
    if (gst[m-1] > 0) ans = max(ans, pref[gst[m-1]-1]);

    for (int i=1; i<m; ++i) {
        int nw = 0;
        if (gst[m-1-i] > 0) nw = pref[gst[m-1-i]-1] - pref[fst[i-1]];
        ans = max(ans, nw);
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

#define pb push_back

void solve() {
    int n = 500; // puzzle
    vector key(0, vi()), lock(0, vi());
    for (int i=0; i<n; ++i) {
        vector<string> g(7);
        for (int j=0; j<7; ++j) cin >> g[j];
        if (g[0][0] == '.') {
            key.pb({});
            for (int h=0; h<5; ++h) {
                int cnt = 0;
                while (cnt < 7 and g[cnt][h] == '.') ++cnt;
                key.back().pb(7-cnt);
            }
        } else {
            lock.pb({});
            for (int h=0; h<5; ++h) {
                int cnt = 0;
                while (cnt < 7 and g[cnt][h] == '#') ++cnt;
                lock.back().pb(cnt);
            }
        }
    }

    int ans = 0;
    for (vi& k: key) for (vi& l: lock) {
        int ok = 1;
        for (int i=0; i<5; ++i) if (k[i] + l[i] > 7) ok = 0;
        ans += ok;
    }

    cout << ans << '\n';
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();
}

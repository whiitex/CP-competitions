#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

const int INF = 1e18;

void solve() {
    int n, m, q; cin >> n >> m >> q;
    vi a(n); for (int &i: a) cin >> i;
    vi b(m); for (int &i: b) cin >> i;

    vi remap(n+1);
    for (int i=0; i<n; ++i) remap[a[i]] = i+1;

    vector pos(n+2, set<int>{INF});
    pos[0].insert(-1);
    for (int i=0; i<m; ++i) {
        b[i] = remap[b[i]];
        pos[b[i]].insert(i);
    }

    set<int> wrong;
    int ans = 1;
    for (int i=0; i<m; ++i) {
        int val = b[i];
        if (*pos[val-1].begin() > i) {
            ans = 0;
            wrong.insert(val);
        }
    }

    if (ans) cout << "Ya\n";
    else cout << "Tidak\n";

    while (q--) {
        int s, t; cin >> s >> t; --s;
        t = remap[t];

        // position update
        pos[b[s]].erase(s);
        pos[t].insert(s);

        if (*pos[b[s]].begin() >= *pos[b[s]-1].begin())
            wrong.erase(b[s]);
        else wrong.insert(b[s]);

        if (*pos[b[s]].begin() <= *pos[b[s]+1].begin())
            wrong.erase(b[s]+1);
        else wrong.insert(b[s]+1);

        b[s] = t;
        if (*pos[b[s]].begin() >= *pos[b[s]-1].begin())
            wrong.erase(b[s]);
        else wrong.insert(b[s]);

        if (*pos[b[s]].begin() <= *pos[b[s]+1].begin())
            wrong.erase(b[s]+1);
        else wrong.insert(b[s]+1);


        if (wrong.empty()) cout << "Ya\n";
        else cout << "Tidak\n";
    }

}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

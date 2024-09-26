#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef long double ld;
typedef pair<int,int> pii; typedef pair<ld,ld> pld;
typedef vector<int> vi; typedef vector<pii> vpii;

#define pb push_back
#define f first
#define s second

const ld EPS = 1e-9;
const ld INF = 1e20;

void solve() {
    int n; cin >> n;
    vpii vec(n); for (pii &i: vec) cin >> i.f >> i.s;

    if (n < 5) { cout << "YES\n"; return; }


    bool _continue = true;
    int index; ld mm, qq;
    for (int rep=0; rep < 5 and _continue; ++rep) {
        map<pld,int> mp;
        index = rep;
        ld x0 = vec[rep].f, y0 = vec[rep].s;

        for (int i=0; i<n and _continue; ++i) if (i != rep) {
            ld x1 = vec[i].f, y1 = vec[i].s;
            ld m = x1 != x0 ? (y1 - y0) / (x1 - x0) : INF;
            ld q = x1 != x0 ? y0 - x0 * m : x0;
            ++mp[{m, q}];
            if (mp[{m, q}] == 2) {
                mm = m; qq = q; _continue = false;
            }
        }
    }

    if (_continue) { cout << "NO\n"; return; }

    vector<bool> done(n, 0);
    done[index] = 1;
    for (int i=0; i<n; ++i) if (i != index) {
        ld x0 = vec[index].f, y0 = vec[index].s;
        ld x1 = vec[i].f, y1 = vec[i].s;
        ld m = x1 != x0 ? (y1 - y0) / (x1 - x0) : INF;
        ld q = x1 != x0 ? y0 - x0 * m : x0;
        if (mm == m and qq == q) done[i] = 1;
    }

    {   // remaining only one or two points
        int count = 0;
        for (bool i: done) if (!i) ++count;
        if (count < 3) { cout << "YES\n"; return; }
    }

    int u = 0; while (u < n and done[u]) ++u;
    int v = u+1; while (v < n and done[v]) ++v;
    ld x0 = vec[u].f, y0 = vec[u].s;
    ld x2 = vec[v].f, y2 = vec[v].s;
    mm = x2 != x0 ? (y2 - y0) / (x2 - x0) : INF;
    qq = x2 != x0 ? y0 - x0 * mm : x0;

    bool yes = true;
    for (int i=v+1; i<n and yes; ++i) if (!done[i]) {
        ld x1 = vec[i].f, y1 = vec[i].s;
        ld m = x1 != x0 ? (y1 - y0) / (x1 - x0) : INF;
        ld q = x1 != x0 ? y0 - x0 * m : x0;
        if (mm != m or qq != q) yes = false;
    }

    if (yes) cout << "YES\n";
    else cout << "NO\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; // cin >> t;
    while (t--) solve();
}

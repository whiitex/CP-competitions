#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n; cin >> n;
    vector<string> g(2);
    cin >> g[0] >> g[1];

    int e = 0, o = 0;
    for (int i=0, x=0; i<n; ++i) {
        e += g[x][i] == '0';
        x ^= 1;
        o += g[x][i] == '0';
    }

    int ne = (n + 1) / 2, no = n / 2;
    if (e >= ne and o >= no) cout << "YES\n";
    else cout << "NO\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

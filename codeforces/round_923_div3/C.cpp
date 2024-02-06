#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, k, j; cin >> n >> m >> k;
    set<int> a;
    for(int i=0; i<n; ++i) {
        cin >> j;
        a.insert(j);
    }
    set<int> b;
    for(int i=0; i<m; ++i) {
        cin >> j;
        b.insert(j);
    }

    int counta = 0;
    int countb = 0;
    for (int i=1; i<=k; ++i) {
        bool isa = a.find(i) != a.end();
        bool isb = b.find(i) != b.end();
        if (isa and isb)
            continue;
        else if (isa and !isb)
            ++counta;
        else if (isb and !isa)
            ++countb;
        else {
            cout << "NO\n";
            return;
        }
    }

    if (counta <= k/2 and countb <= k/2)
        cout << "YES\n";
    else cout << "NO\n";

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}

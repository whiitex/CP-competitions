#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int x, y; cin >> x >> y;

    if (x+1 == y) { cout << "YES\n"; return; }
    if (x == y) { cout << "NO\n"; return; }
    if (x > y and (-y+x+1) % 9 == 0) { cout << "YES\n"; return; }
    cout << "NO\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n, a, b; cin >> n >> a >> b;
    string s; cin >> s;

    int x = 0, y = 0;
    for (int i=0; i<100; ++i) {
        for (char c: s) {
            if (c == 'E') ++x;
            if (c == 'W') --x;
            if (c == 'N') ++y;
            if (c == 'S') --y;

            if (x == a and y == b) {
                cout << "YES\n"; return;
            }
        }
    }

    cout << "NO\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

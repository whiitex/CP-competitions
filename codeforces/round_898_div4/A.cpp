#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        cout << (s == "cab" or s == "bca" ? "NO" : "YES") << '\n';
    }
}

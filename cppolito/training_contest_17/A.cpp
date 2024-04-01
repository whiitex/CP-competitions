#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int a = std::count(s.begin(), s.end(), 'A');
        int b = std::count(s.begin(), s.end(), 'B');
        cout << (a > b ? 'A' : 'B') << '\n';
    }
}

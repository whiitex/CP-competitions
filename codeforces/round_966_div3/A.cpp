#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    string s; cin >> s;

    if (s[0] != '1') {
        cout << "NO\n";
        return;
    };

    bool valid = true;
    for (int i=1; i<s.size(); ++i) if (s[i] != '0') valid = false;

    if (!valid and s != "100" and s != "101" and s.size() > 2 and s[2] != '0' and s[1] == '0') {
        cout << "YES\n";
    } else cout << "NO\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

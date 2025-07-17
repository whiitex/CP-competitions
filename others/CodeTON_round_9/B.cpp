#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    string s; cin >> s;

    if (s.size() == 1) { cout << -1 << '\n'; return; }

    for (int i=1; i<s.size(); ++i) {
        if (s[i] == s[i-1]) {
            cout << s[i-1] << s[i] << '\n';
            return;
        }
    }

    for (int i=2; i<s.size(); ++i) {
        if (s[i] != s[i-1] and s[i] != s[i-2] and s[i-1] != s[i-2]) {
            cout << s[i-2] << s[i-1] << s[i] << '\n';
            return;
        }
    }

    cout << -1 << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

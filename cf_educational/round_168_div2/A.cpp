#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s; cin >> s;
    for (int i=0; i<s.size()-1; ++i) {
        if (s[i] == s[i+1]) {
            cout << s.substr(0, i+1);
            if (s[i] == 'z') cout << 'a';
            else cout << 'z';
            cout << s.substr(i+1, s.size()-i-1) << '\n';
            return;
        }
    }
    if (s[0] == 'z') cout << 'a';
    else cout << 'z';
    cout << s << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

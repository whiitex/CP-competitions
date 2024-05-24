#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s; cin >> s;
    if (std::count(s.begin(), s.end(), s[0]) == s.size()) {
        cout << "No" << '\n'; return;
    } else cout << "Yes" << '\n';

    int i=1;
    while (s[i] == s[0]) ++i;
    swap(s[i], s[0]);
    cout << s << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}

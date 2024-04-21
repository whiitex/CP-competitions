#include <bits/stdc++.h>

using namespace std;


void solve() {
    string s; cin >> s;
    int one=0, zero=0;
    for (char c: s) {
        if (c == '0') ++zero;
        else ++one;
    }

    for (int i=0; i<s.size(); ++i) {
        char c = s[i];
        if (c == '0' and one) --one;
        else if (c == '1' and zero) --zero;
        else {
            cout << s.size() - i << '\n';
            return;
        }
    }

    cout << 0 << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}

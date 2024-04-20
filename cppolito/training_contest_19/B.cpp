#include <bits/stdc++.h>

using namespace std;

string solve() {
    string s, t; cin >> s >> t;
    int n = s.length();
    for (int i=0; i<n-1; ++i) {
        if (s[i] == '0' and t[i] == '0' and s[i+1] == '1' and t[i+1] == '1')
            return "Yes";
    }

    return "No";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) cout << solve() << '\n';
}

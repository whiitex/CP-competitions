#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    string s, t; cin >> s >> t;

    int i = 0;
    for (; i<min(s.size(), t.size()); ++i) {
        if (s[i] != t[i]) break;
    }

    int ans = s.size() + t.size() - i;
    if (i) ++ans;

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

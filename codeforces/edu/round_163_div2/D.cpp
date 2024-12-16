#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s; cin >> s;

    int ans = 0;
    for (int t=2; t<=s.size(); t+=2) {
        int bad = 0;
        for (int i=0; i<t/2; ++i) {
            if (s[i] == '?' or s[i+t/2] == '?' or s[i] == s[i+t/2]) continue;
            ++bad;
        }

        for (int i=1; i+t-1<s.size() and bad>0; ++i) {
            if (s[i-1] == '?' or s[i-1+t/2] == '?' or s[i-1] == s[i-1+t/2]) {}
            else --bad;

            int r = i+t/2 - 1;
            if (s[r] == '?' or s[r+t/2] == '?' or s[r] == s[r+t/2]) continue;
            ++bad;
        }

        if (bad == 0) ans = t;
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

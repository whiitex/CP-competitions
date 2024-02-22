#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n, k, ans=0; cin >> n >> k;
        string s; cin >> s;

        for (int i=0; i<s.length(); ++i) {
            if (s[i] == 'B') {
                i += k-1;
                ++ans;
            }
        }

        cout << ans << '\n';
    }
}
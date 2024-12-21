#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    int removed = -1;
    for (int i=1; i<n; ++i) {
        if (s[i] < s[i-1]) {
            removed = i-1;
            break;
        }
    }

    if (removed == -1) removed = n-1;
    for (int i=0; i<n; ++i) {
        if (i != removed) cout << s[i];
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();
}

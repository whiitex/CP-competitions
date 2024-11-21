#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    if (s[0] == '1' or s[n-1] == '1') { cout << "YES\n"; return; }

    bool ok = false;
    for (int i=1; i<n; ++i) {
        if (s[i] == '1' and s[i-1] == '1') ok = true;
    }

    if (ok) cout << "YES\n";
    else cout << "NO\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    int ok = 1, cp=0, cs=0;
    for (int i=0; i<n; ++i) {
        if (i==0 and s[i] == 's') continue;
        if (i==n-1 and s[i] == 'p') continue;

        if (s[i] == 's') ++cs;
        if (s[i] == 'p') ++cp;
    }

    ok = !cs or !cp;
    cout << (ok ? "YES" : "NO") << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

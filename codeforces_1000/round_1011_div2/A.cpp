#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;

    int allsame = 1;
    for (int i=1; i<n; ++i) if (s[i] != s[0]) allsame = 0;

    if (allsame) { cout << "NO\n"; return; }

    string r = s;
    reverse(r.begin(), r.end());

    if (r <= s and k == 0) cout << "NO\n";
    else cout << "YES\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

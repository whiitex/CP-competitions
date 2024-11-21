#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n; cin >> n;

    if (n == 1) { cout << 0 << '\n'; return; }

    for (int i=0; i<n-1; ++i) cout << 0;
    cout << 1 << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

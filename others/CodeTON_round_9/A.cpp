#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n; cin >> n;

    for (int i=1; i<=n; ++i) {
        cout << i + i-1 << ' ';
    } cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

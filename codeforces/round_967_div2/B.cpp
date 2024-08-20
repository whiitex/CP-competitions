#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n; cin >> n;

    if (n % 2 == 0) {
        cout << -1 << '\n';
        return;
    }

    cout << 1 << ' ';
    for (int i=1; i<=n/2; ++i) {
        cout << n+1-i << ' ' << i+1  << ' ';
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

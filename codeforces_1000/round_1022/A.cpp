#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n; cin >> n;

    int mx = 0;
    for (int i=1; i<=n/2; ++i) {
        mx += 2 * ((n-i+1) - i);
    }

    cout << 1 + mx/2 << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

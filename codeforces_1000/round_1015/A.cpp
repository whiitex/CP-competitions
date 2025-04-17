#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n; cin >> n;

    if (n % 2 == 0)  cout << -1 << '\n';
    else if (n % 3 == 2) {
        cout << 1 << ' ' << n << ' ';
        for (int i=2; i<n; ++i) cout << i << ' ';
        cout << '\n';
    } else {
        cout << n << ' ' << 1 << ' ';
        for (int i=2; i<n; ++i) cout << i << ' ';
        cout << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

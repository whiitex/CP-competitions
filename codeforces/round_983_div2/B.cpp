#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k; cin >> n >> k;

    if (n == 1) { cout << "1\n1\n"; return; }

    if (k == 1 or k == n) {cout << "-1\n"; return;}

    if (k % 2 == 0) {
        cout << 3 << '\n';
        cout << "1 " << k << " " << k+1 << '\n';
    } else {
        cout << 5 << '\n';
        cout << "1 2 " << k << ' ' << k+1 << ' ' << k+2 << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

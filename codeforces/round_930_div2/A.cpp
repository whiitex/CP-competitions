#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t, n; cin >> t;
    while (t--) {
        cin >> n;
        cout << (1 << (int)log2(n)) << '\n';
    }
}

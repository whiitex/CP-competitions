#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve() {
    int n, k; cin >> n >> k;
    if (n == 1) {cout << k << '\n'; return;}

    int mx = -1;
    int kk = k;
    while (kk) {
        ++mx; kk >>= 1;
    }

    cout << (int)((1 << mx) -1) << ' ';
    cout << (int)(k - ((1<<mx) -1)) << ' ';
    for (int i=0; i<n-2; ++i) cout << 0 << ' ';
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}

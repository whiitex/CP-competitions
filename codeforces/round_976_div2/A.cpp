#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n, k; cin >> n >> k;
    if (k == 1) {
        cout << n << '\n'; return;
    }
    int sub = 1; while (sub < n) sub *= k;
    int ans = 0;
    while (n > 0) {
        if (sub <= n) {
            int add = n / sub;
            ans += add;
            n -= add * sub;
        }
        sub /= k;
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int k; cin >> k;

    int l = 1, r = 1e10;
    while (l < r) {
        int mid = l + r + 1 >> 1;

        if ((mid) * (mid-1) >= k) r = mid-1;
        else l = mid;
    }

    int ans = l*l + (k - (l-1)*l);
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

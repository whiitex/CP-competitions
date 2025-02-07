#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;


void solve() {
    int n, k; cin >> n >> k;
    vi a(n); for (int &i: a) cin >> i;

    if (n == k) {
        int ans = 1;
        for (int i=1; i<n; i+=2) {
            if (a[i] != ans) break;
            ++ans;
        }

        cout << ans << '\n'; return;
    }

    int ans = 2;
    for (int i=1; i+k<=n+1; ++i) {
        if (a[i] != 1) ans = 1;
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

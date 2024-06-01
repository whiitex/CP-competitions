#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

#define pb push_back

void solve() {
    int n, m; cin >> n >> m;
    vi vec(n); for (int &i: vec) cin >> i;

    vi dp(n, 1);
    for (int i=1; i<n; ++i) {
        if (vec[i] == vec[i-1])
            dp[i] = dp[i-1] + 1;
        else dp[i] = dp[i-1] + i + 1;
    }

    int ans = 0;
    for (int i: dp) ans += i;

    while (m--) {
        int i, a; cin >> i >> a; --i;

        if (vec[i] == a) {
            cout << ans << '\n'; continue;
        }

        if (i < n-1) {
            int delta = i+1;

            if (vec[i] == vec[i+1])
                ans += delta * (n-i-1);
            else if (vec[i+1] == a)
                ans -= delta * (n-i-1);
        }

        if (i > 0) {
            int delta = i;

            if (vec[i] == vec[i-1])
                ans += delta * (n-i);
            else if (vec[i-1] == a)
                ans -= delta * (n-i);
        }

        vec[i] = a;
        cout << ans << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1; // cin >> t;
    while (t--) solve();
}

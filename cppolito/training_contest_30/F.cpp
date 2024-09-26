#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

const int INF = 1e9;

void solve() {
    int n, k; cin >> n >> k;
    vi vec(n); for (int &i: vec) cin >> i;

    function check = [&] (int median) -> bool {
        vi b(n, 0);
        for (int i=0; i<n; ++i) b[i] = 2 * (vec[i] >= median) - 1;

        vi dp(n, 0); dp[0] = b[0];
        for (int i=1; i<min(n,k); ++i) dp[i] = dp[i-1] + b[i];

        for (int i=k; i<n; ++i) {
            if (i % k) {
                dp[i] = max(dp[i-1] + b[i], dp[i-k]);
            } else dp[i] = max(dp[i-k], b[i]);
        }

        return dp[n-1] > 0;
    };

    int l=1, r = 1e9;
    while (l < r) {
        int mid = l + r +1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }

    cout << l << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

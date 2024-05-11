#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

#define pb push_back

void solve() {
    int n; cin >> n;
    vi vec(n); for (int &i: vec) cin >> i;
    vi rem(n+1, n+10);

    vi dp(n+1);
    for (int i=1; i<=n; ++i) {
        dp[i] = min(dp[i-1]+1, rem[vec[i-1]]);
        rem[vec[i-1]] = min(dp[i-1], rem[vec[i-1]]);
    }

    cout << n - dp[n] << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;

const int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vi a(n); for (int &i: a) cin >> i;

    vi p(n+1); for (int i=1; i<=n; ++i) p[i] = a[i-1] ^ p[i-1];
    map<int,int> dp; dp[0] = 1;
    for (int i=1; i<=n; ++i) {
        dp[p[i-1]] = (3 * dp[p[i-1]] + 2 * dp[p[i]]) % MOD;
    }

    int ans = 0;
    for (auto [_, x]: dp) ans = (ans + x) % MOD;
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

const int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vi b(n); for (int &i: b) cin >> i;

    map<int,int> dp; dp[0] = 1;
    int sm = 0, ans = 1;
    for (int bi: b) {
        int bad = dp[sm];
        dp[sm] = ans;
        sm -= bi;
        ans = (2 * ans - bad + MOD) % MOD;
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

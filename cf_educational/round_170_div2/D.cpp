#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
    int n, m; cin >> n >> m;
    vi r(n); for (int &i: r) cin >> i;

    vector dp(m+1, vi(m+1));
    int lev = 0, i = 0;
    while (r[i] != 0) ++i;

    for (; i<n;) {
        vi strvec(m+1), intvec(m+1);
        int j=i+1, inte = 0, stre = 0;

        for (; j<n; ++j) {
            if (r[j] == 0) break;

            if (r[j] > 0) ++intvec[r[j]];
            else ++strvec[-r[j]];

            if (r[j] > 0 and r[j] <= lev) ++inte;
        }

        for (int l=0; l<=lev; ++l) {
            dp[lev-l + 1][l] = max(dp[lev-l + 1][l], dp[lev-l][l] + inte + stre + intvec[lev-l+1]);
            dp[lev-l][l+1] = max(dp[lev-l][l+1], dp[lev-l][l] + inte + stre + strvec[l+1]);

            inte -= intvec[lev-l];
            stre += strvec[l+1];
        }

        i = j;
        ++lev;
    }

    int ans = 0;
    for (int l=0; l<=m; ++l) ans = max(ans, dp[m-l][l]);
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; // cin >> t;
    while (t--) solve();
}

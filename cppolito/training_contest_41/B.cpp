#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;

const int MXN = 2e5;

void solve() {
    int n; cin >> n;
    vi a(n); for (int &i: a) cin >> i;

    vi dp(MXN+1); for (int i: a) ++dp[i];
    int mx = 0, lx, rx;
    for (int l=1; l<=MXN; ++l) if (dp[l]) {
        int r = l+1, sm = dp[l];
        while (r <= MXN and dp[r] > 1) sm += dp[r++];
        if (dp[r] == 1) ++sm;

        if (sm > mx) {
            mx = sm;
            lx = l; rx = r - (dp[r] == 1 ? 0 : 1);
        }
        l = r-1;
    }

    cout << mx << '\n';
    for (int i=lx; i<=rx; ++i) {
        cout << i << ' '; --dp[i];
    }
    for (int i=rx; i>=lx; --i) {
        while (dp[i]--) cout << i << ' ';
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();
}

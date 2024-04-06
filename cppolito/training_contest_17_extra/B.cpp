#include <bits/stdc++.h>

using namespace std;
#define int long long

typedef vector<int> vi;

void solve() {
    int n, ans = 0; cin >> n;
    vi vec(n); for (int &i: vec) cin >> i;
    vi upd(n, 0);

    for (int i=0; i<n; ++i) {

        if (vec[i] == 1 and i<n-1) {
            upd[i+1] += upd[i];
            continue;
        }

        int val = vec[i] - upd[i];
        if (val < 1 and i<n-1) upd[i+1] += -val + 1;
        else if (val > 1) ans += val - 1;

        for (int k=2; k <= vec[i] and i+k<n; ++k) ++upd[i+k];
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}

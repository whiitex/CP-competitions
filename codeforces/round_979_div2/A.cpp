#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

const int INF = 1e18;

void solve() {
    int n; cin >> n;
    vi vec(n); for (int &i: vec) cin >> i;

    int mx = 0, mn = INF;
    for (int i: vec) {
        mx = max(mx, i);
        mn = min(mn, i);
    }

    int ans = (n-1) * (mx - mn);
    cout << ans << '\n';

}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

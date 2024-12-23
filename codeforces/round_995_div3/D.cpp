#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
    int n, x, y; cin >> n >> x >> y;
    vi a(n); for (int &i: a) cin >> i;

    int sm = 0; for (int i: a) sm += i;

    sort(a.begin(), a.end());

    int ans = 0;
    for (int i: a) {
        int tot = sm - i;
        int good = n - (lower_bound(a.begin(), a.end(), tot - y) - a.begin());
        if (good == 0) continue;

        int bad = n - (upper_bound(a.begin(), a.end(), tot - x) - a.begin());
        if (bad == n) continue;

        ans += good - bad;
        if (tot - i >= x and tot - i <= y) ans--;
    }

    ans /= 2;
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

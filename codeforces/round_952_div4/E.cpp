#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
    int x, y, z, k; cin >> x >> y >> z >> k;
    vi lats{x, y, z};
    sort(lats.begin(), lats.end());

    int ans = 0;
    for (int i=1; i<=min(lats[2], k); ++i) {
        if (k % i) continue;
        int k2 = k/i;
        for (int j=1; j<=min(lats[2],k2); ++j) {
            if (k2 % j) continue;
            int k3 = k2 / j;

            vi lens {i, j, k3};
            sort(lens.begin(), lens.end());
            bool ok = true;
            for (int q=0; q<3; ++q) if (lens[q] > lats[q]) ok = false;

            if (!ok) continue;

            int ans2 = 1;
            for (int q=0; q<3; ++q) ans2 *= (lats[q] + 1 - lens[q]);
            ans = max(ans, ans2);
        }
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

void solve() {
    int n; cin >> n;
    vi vec(n); for(int& i: vec) cin >> i;

    vi veck;
    for (int i=1; i<=n; ++i)
        if (n % i == 0)
            veck.push_back(i);

    int ans = 0;
    for (int k: veck) {
        if (k == n) {
            ++ans; continue;
        }

        int gcd = 0;
        for (int i=0; i<n-k; ++i) {
            if (vec[i] - vec[i+k] == 0) continue;
            if (gcd == 0) gcd = abs(vec[i] - vec[i + k]);
            else gcd = __gcd(gcd, abs(vec[i] - vec[i + k]));
        }

        if (gcd != 1) ++ans;
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

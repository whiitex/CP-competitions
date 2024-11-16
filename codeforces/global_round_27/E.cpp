#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int x, y, z, k; cin >> x >> y >> z >> k;

    int ans = x + y*z, limz = (int)sqrt(z) + 1ll;
    for (int i=1; i <= limz; ++i) {
        int hits = i/k;
        int damage = k * ((hits * (hits+1)) /2);

        if (damage >= z) {
            ans = min(ans, hits*y + i*x);
            break;
        }

        int cost = i*x + y* ((z - damage + i-1) / i) + y*hits;
        ans = min(ans, cost);
    }

    for (int i=1; i <= limz; ++i) {
        int l=1, r=1e9;
        while (l < r) {
            int att = l+r >> 1;
            int damage = att * i + k * (((att-1)/k * ((att-1)/k+1))/2);

            if (damage >= z) r = att;
            else l = att + 1;
        }

        int attack = l;
        int hits = (attack-1)/k;

        int cost = x*attack + y*hits + y*i;
        ans = min(ans, cost);
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

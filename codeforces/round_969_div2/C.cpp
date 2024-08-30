#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

#define pb push_back

void solve() {
    int n, a, b; cin >> n >> a >> b;
    vi vec(n); for (int &i: vec) cin >> i;

    sort(vec.begin(), vec.end());

    int ans = 0;
    int mx = vec[n-1];
    int k = __gcd(a, b);
    vi kd;
    for (int i=0; i<n-1; ++i) {
        int diff = mx - vec[i];
        int upd1 = diff % k;
        kd.pb(upd1);
        ans = max(ans, upd1);
    }

    kd.pb(0);
    sort(kd.begin(), kd.end(), greater<>());

    int big = 0;
    for (int i=0; i<n; ++i) {
        int diff = k - kd[i];
        big = diff;
        if (i < n-1) ans = min(ans, kd[i+1] + big);
        else ans = min(ans, big);
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

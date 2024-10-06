#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
    int n, k; cin >> n >> k;
    vi vec(n); int sum = 0;
    for (int &i: vec) {
        cin >> i; sum += i;
    }

    sort(vec.begin(), vec.end());
    vi pref(n); pref[0] = vec[0];
    for (int i=1; i<n; ++i) pref[i] = pref[i-1] + vec[i];

    if (vec[n-1] * n - pref[n-1] <= k) {
        cout << n << '\n'; return;
    }

    int ans = 1;
    for (int i=2; i<=n; ++i) {
        int req = 0;
        if (sum % i != 0) req += i - (sum % i);
        if (vec[n-1] > (sum + req) / i) {
            int mul = (vec[n-1] * i - (sum + req) + i - 1) / i;
            req += i * mul;
        }

        if (req <= k) ans = max(ans, i);
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

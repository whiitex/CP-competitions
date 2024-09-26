#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

bool is(int a, int b, int c) {
    if (a > b and c > b) return 1;
    return (a < b and c < b);
}

void solve() {
    int n; cin >> n;
    vi vec(n); for (int &i: vec) cin >> i;

    vi a(n, 0);
    int original = 0, out = 1;
    for (int i=1; i<n-1; ++i) {
        if (is(vec[i-1], vec[i], vec[i+1])) a[i] = 1;
        original += a[i];
    }

    int ans = original;
    for (int i=1; i<n-1; ++i) {
        int prev = a[i] + a[i-1] + a[i+1];

        int veci = vec[i-1], now = 0;
        if (i > 1 and is(vec[i-2], vec[i-1], veci)) ++now;
        if (i < n-2 and is(veci, vec[i+1], vec[i+2])) ++now;
        if (is(vec[i-1], veci, vec[i+1])) ++ now;

        ans = min(ans, original - prev + now);

        veci = vec[i+1], now = 0;
        if (i > 1 and is(vec[i-2], vec[i-1], veci)) ++now;
        if (i < n-2 and is(veci, vec[i+1], vec[i+2])) ++now;
        if (is(vec[i-1], veci, vec[i+1])) ++ now;

        ans = min(ans, original - prev + now);
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

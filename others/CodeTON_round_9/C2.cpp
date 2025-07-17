#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

#define pb push_back

void solve() {
    int x, m; cin >> x >> m;
    // int naive = 0;
    // for (int i=1; i<=m; ++i) {
    //     int d = i^x;
    //     if (d%x == 0 or d%i == 0) ++naive;
    // }

    if (x == 1) { cout << m << '\n'; return; }

    int tot = 32 - __builtin_clz(x);
    int prev = __builtin_ctz(x);
    int lenc = 1 << (tot - prev);

    vi temp = {x};
    int mul = 2*x;
    for (int i=0; i<3*lenc; ++i) {
        temp.pb(mul^x);
        mul += x;
    }
    sort(temp.begin(), temp.end());

    vi cyc;
    for (int i=1; i<=lenc; ++i) cyc.pb(temp[i] - temp[i-1]);

    int cnt = 0;
    for (int i=1; i<=min(x, m); ++i) {
        int d = i ^ x;
        if (d%x == 0 or d%i == 0) ++cnt;
    }

    if (__builtin_popcount(x) == 1) {
        int add = (m-x) / x;
        cout << cnt + add   << '\n';
        return;
    }

    if (m < x) { cout << cnt  << '\n'; return; }

    int sm = 0; for (int i: cyc) sm += i;
    cnt += lenc * ((m - x) / sm);

    m = (m-x) % sm;
    for (int i=0; i<lenc and m > 0; ++i) {
        if (m >= cyc[i]) ++cnt;
        m -= cyc[i];
    }

    cout << cnt << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

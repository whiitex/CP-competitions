#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
    int n; cin >> n;
    vi vec(2*n); for (int &i: vec) cin >> i;

    int ct = 0;
    for (int i: vec) if (i) ++ct;

    int mx = min(ct, n);
    if (ct > n) mx -= ct - n;
    cout << (ct&1) << ' ' << mx << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

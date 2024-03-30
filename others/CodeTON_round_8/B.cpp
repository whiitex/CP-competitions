#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

void solve() {
    int n; cin >> n;
    vi vec(n); for (int& i: vec) cin >> i;

    int mn = n;
    vi ans(n);
    for (int i=n-1; i>=0; --i) {
        ans[i] = mn - vec[i];
        mn = min (mn, ans[i]);
    }

    for (int i: ans) cout << i << ' ';
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}

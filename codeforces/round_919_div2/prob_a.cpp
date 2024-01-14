#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
const ll INF = 1e9;

void solve() {
    int n, mn=0, mx=INF+1;; cin >> n;
    vi vec;
    for (int i=0; i<n; ++i) {
        int a, x; cin >> a >> x;
        if (a == 1) mn = max(mn, x);
        else if (a == 2) mx = min(mx, x);
        else vec.push_back(x);
    }
    int ans = 0;
    if (mn <= mx) ans = mx - mn + 1;
    for (int i: vec)
        if (i >= mn and i <=mx) --ans;
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

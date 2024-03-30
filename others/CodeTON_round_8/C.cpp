#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

void solve() {
    ll n, x, y; cin >> n >> x >> y;
    vi vec(x); for (int& i: vec) cin >> i;
    std::sort(vec.begin(), vec.end());

    ll ans = x-2;
    for (int i=0; i<x-1; ++i) {
        if (vec[(i+1)%n] - vec[i] == 2) ++ans;
    }

    if ((vec[0] + n - vec[x-1]) == 2) ++ans;

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

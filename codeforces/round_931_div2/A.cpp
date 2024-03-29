#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

void solve() {
    int n; cin >> n;
    vi vec(n); for (int &i: vec) cin >> i;
    std::sort(vec.begin(), vec.end());

    ll ans = 0;
    ans += 2*abs(vec[0]-vec[n-1]);
    ans += 2*abs(vec[1]-vec[n-2]);
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

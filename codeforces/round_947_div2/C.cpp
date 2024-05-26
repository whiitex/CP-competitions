#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

#define pb push_back

void solve() {
    int n; cin >> n;
    vi vec(n); for (int &i: vec) cin >> i;

    if (n == 2) {
        cout << min(vec[0], vec[1]) << '\n';
        return;
    }

    int ans = -1;
    for (int i=0; i<n-2; ++i) {
        vi v;
        v.pb(vec[i]);
        v.pb(vec[i+1]);
        v.pb(vec[i+2]);
        std::sort(v.begin(), v.end());
        ans = max(ans, v[1]);
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}

#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

#define pb push_back

void solve() {
    int n; cin >> n;

    if (n == 1 or n == 3) { cout << -1 << '\n'; return; }

    if (n & 1) {
        vi ans = {6, 6, 3, 6};
        for (int i=4; i<n; ++i) ans.pb(3);
        reverse(ans.begin(), ans.end());
        for (int i: ans) cout << i;
    } else {
        for (int i=0; i<n-2; ++i) cout << 3;
        cout << 66;
    }

    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

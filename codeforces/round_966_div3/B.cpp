#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
    int n; cin >> n;
    vi vec(n); for (int &i: vec) cin >> i;

    int mn = vec[0], mx = vec[0];
    for (int i=1; i<n; ++i) {
        if (vec[i] != mn -1 and vec[i] != mx + 1) {
            cout << "NO\n";
            return;
        }
        mn = min (mn, vec[i]);
        mx = max (mx, vec[i]);
    }

    cout << "YES\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

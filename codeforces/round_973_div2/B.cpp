#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
    int n; cin >> n;
    vi vec(n); for (int &i: vec) cin >> i;

    if (n == 2) cout << vec[1] - vec[0] << '\n';
    else {
        for (int i=0; i<n-2; ++i) vec[n-2] -= vec[i];
        vec[n-1] -= vec[n-2];
        cout << vec[n-1] << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

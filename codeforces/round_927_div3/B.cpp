#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

void solve() {
    int n; cin >> n;
    vi vec(n); for (int& i: vec) cin >> i;

    ll now = vec[0];
    for (int i=1; i<n; ++i) {
        if (now < vec[i]) now = vec[i];
        else now = ((now / vec[i]) + 1) * vec[i];
    }
    cout << now << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}

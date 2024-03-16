#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

void solve() {
    int n; cin >> n;
    vi vec(n); for (int& i: vec) cin >> i;

    int i=0;
    while (i < n and vec[i] >= i) ++i;
    --i;

    int j= n-1;
    while (j >= 0 and vec[j] >= n-j-1) --j;
    ++j;
    cout << (i >= j ? "Yes" : "No") << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}

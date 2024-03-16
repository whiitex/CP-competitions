#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

void solve() {
    int n; cin >> n;
    vi vec(n+1,0);
    for (int i=0; i<n; ++i) {
        int a; cin >> a;
        ++vec[a];
    }

    bool flag = false;
    for (int i=0; i<=n; ++i) {
        if (vec[i] == 0) {
            cout << i << '\n';
            return;
        }

        if (vec[i] == 1 and flag) {
            cout << i << '\n';
            return;
        } else if (vec[i] == 1) flag = true;
    }

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}

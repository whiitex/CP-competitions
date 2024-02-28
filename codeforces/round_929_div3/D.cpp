#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

void solve() {
    int n; cin >> n;
    vi vec(n); for (int& i: vec) cin >> i;
    std::sort(vec.begin(), vec.end());

    if (vec[0] == vec[1] and n == 2) {
        cout << "No\n";
        return;
    } else if (vec[0] == vec[1]) {
        int i = 2;
        while (vec[i] % vec[0] == 0 and i < n) ++i;
        if (i == n) {
            cout << "No\n";
            return;
        } else cout << "Yes\n";
    } else {
        cout << "Yes\n";
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

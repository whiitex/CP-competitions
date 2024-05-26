#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
    int n; cin >> n;
    vi vec(n); for (int &i: vec) cin >> i;

    bool ok = false;
    for (int i=0; i<n; ++i) {
        int check = true;
        for (int j=0; j<n-1; ++j) {
            if (vec[(i+j)%n] > vec[(i+j+1)%n])
                check = false;
        }
        if (check) ok = check;
    }

    if (ok) cout << "Yes\n";
    else cout << "No\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}

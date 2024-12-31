#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
    int n; cin >> n;
    vi vec(n); for (int &i: vec) cin >> i;
    // sort (vec.begin(), vec.end());

    for (int i=1; i<n; ++i) {
        int a = min(vec[i], vec[i-1]);
        int b = max(vec[i], vec[i-1]);
        if (b < 2*a) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

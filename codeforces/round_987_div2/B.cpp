#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
    int n; cin >> n;
    vi vec(n); for (int &i: vec) cin >> i;

    int ok = 1;
    for (int i=0; i<n-1 and ok; ++i) {
        if (vec[i] == i+1) continue;

        if (vec[i+1] == i+1 and abs(vec[i] - vec[i+1]) <= 1) {
            swap(vec[i+1], vec[i]);
            continue;
        }

        ok = 0;
    }

    cout << (ok or n<3 ? "YES" : "NO") << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

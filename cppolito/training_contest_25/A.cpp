#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
    int n; cin >> n;
    vi vec(n); for (int &i: vec) cin >> i;

    if (std::count(vec.begin(), vec.end(), vec[0]) == n) {
        cout << 0 << '\n'; return;
    }

    int ans = 0, dec = 0;
    for (int i = n-1; i>0; --i) {
        ans += abs(vec[i] - vec[i-1]);
    }

    dec = max(dec, abs(vec[1] - vec[0]));
    dec = max(dec, abs(vec[n-2] - vec[n-1]));

    for (int i=1; i<n-1; ++i) {
        if (vec[i] > vec[i-1] and vec[i] > vec[i+1]) {
            int better = min(abs(vec[i] - vec[i-1]), abs(vec[i] - vec[i+1]));
            dec = max(2*better, dec);
        }

        if (vec[i] < vec[i-1] and vec[i] < vec[i+1]) {
            int better = min(abs(vec[i] - vec[i-1]), abs(vec[i] - vec[i+1]));
            dec = max(2*better, dec);
        }
    }

    cout << ans - dec << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}

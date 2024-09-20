#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
    int n; cin >> n;
    vi vec(n); for (int &i: vec) cin >> i;

    if (n == 1) {
        cout << 0 << '\n'; return;
    }

    int mx = vec[n-1];
    int w = 1, h = vec[n-1], sm = vec[n-1];
    for (int i=n-2; i>=0; --i) {
        w += 1; sm += vec[i];
        if (vec[i] > h) {
            h = sm / w;
            mx = max(mx, (sm + w-1) / w);
        }
    }

    int mn = vec[0];
    w = 1; h = vec[0]; sm = vec[0];
    for (int i=1; i<n; ++i) {
        w += 1; sm += vec[i];
        if (vec[i] < h) {
            h = (sm + w-1) / w;
            mn = min(mn, sm / w);
        }
    }

    cout << mx - mn << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

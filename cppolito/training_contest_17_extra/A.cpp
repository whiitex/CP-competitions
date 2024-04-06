#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

void solve() {
    int n; cin >> n;
    vi poor(n), rich(n);
    for (int i=0; i<n; ++i) cin >> rich[i] >> poor[i];

    int l=0, r=n;
    while (l < r) {
        int mid = l+r+1 >> 1;

        int k = 0;
        for (int i=0; i<n && k < mid; ++i) {
            if (poor[i] >= k && rich[i] >= mid - k - 1)
                ++k;
        }

        if (k < mid) r = mid-1;
        else l = mid;
    }

    cout << l << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}

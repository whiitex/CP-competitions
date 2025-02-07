#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;

#define pb push_back

void solve() {
    int n; cin >> n;
    vector g(n, vi(n));
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) cin >> g[i][j];
    }

    vi b;
    for (int q=0; q<n; ++q) {
        int i = n-1, cnt = 0;
        while (i >= 0 and g[q][i] == 1) --i, ++cnt;

        if (cnt) b.pb(cnt);
    }

    sort(b.begin(), b.end());
    int ans = 1;
    for (int i=0; i<b.size(); ++i) {
        if (b[i] < ans) continue;
        ++ans;
    }

    cout << min(n, ans) << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

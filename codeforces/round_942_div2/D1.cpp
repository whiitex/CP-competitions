#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
    int n, m; cin >> n >> m;

    int ans = n;

    for (int i=2; i<=m; ++i) {
        int first = i * (i-1);
        if (first > n) break;
        ++ans;
        ans += (n - first) / (i*i);
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}

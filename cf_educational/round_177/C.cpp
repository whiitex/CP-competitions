#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
    int n; cin >> n;
    vi a(n+1); for (int i=1; i<=n; ++i) cin >> a[i];

    vi pos(n+1); for (int i=1; i<=n; ++i) pos[a[i]] = i;

    vi vis(n+1); int ans = 0;
    for (int _=0; _<n; ++_) {
        int x; cin >> x;

        while (!vis[x]) {
            ++ans;
            vis[x] = 1;
            x = pos[x];
        }
        cout << ans << ' ';
    }

    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

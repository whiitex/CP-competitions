#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
    int n, x, y; cin >> n >> x >> y;
    if (y < x) swap(x, y);

    int in = y-x-1, out = x-1 + n-y;
    vi ans(n+1);
    if (in % 2 != out % 2) {
        if (in % 2) {
            for (int i=x; i<y; i+=2) ans[i] = 0, ans[i+1] = 1;
            ans[y] = 2;
            int i = (y%n) + 1, val = 0;
            while (i != x) {
                ans[i] = val;
                val ^= 1;
                i = (i%n) + 1;
            }
        } else {
            int i = y, val = 0;
            while (i != x) {
                ans[i] = val;
                val ^= 1;
                i = (i%n) + 1;
            }
            ans[x] = 2;
            for (int i=x+1; i<y; i+=2) ans[i] = 0, ans[i+1] = 1;
        }
    } else if (in % 2 == 0) {
        int i = (x%n)+1, val = 1; ans[x] = 0;
        while (i != x) {
            ans[i] = val;
            val ^= 1;
            i = (i%n) + 1;
        }
    } else {
        for (int i=x; i<y; i+=2) ans[i] = 0, ans[i+1] = 1;
        ans[y] = 2;
        int i = (y%n) + 1, val = 1;
        while (i != x) {
            ans[i] = val;
            val ^= 1;
            i = (i%n) + 1;
        }
    }

    for (int i=1; i<=n; ++i) cout << ans[i] << ' '; cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

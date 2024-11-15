#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;
const int MAXN = 5e5 + 5;

void solve() {
    int n; cin >> n;

    if (n % 2 == 0) {
        for (int i=1; i<=n/2; ++i) {
            cout << i << ' ' << i << ' ';
        }
        cout << '\n'; return;
    }

    if (n >= 27) {
        vi ans(n+1);
        ans[2] = ans[18] = ans[27] = 2;
        ans[1] = ans[5] = 1;

        int ch = 0, x = 3;
        for (int i=2; i<=n; ++i) {
            if (ch == 2) {
                ch = 0; ++x;
            }
            if (ans[i] == 0) {
                ans[i] = x; ++ch;
            }
        }

        for (int i=1; i<=n; ++i) cout << ans[i] << ' ';
        cout << '\n';
        return;
    }

    cout << -1 << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

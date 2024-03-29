#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    int n; cin >> n;
    int ans = 0;
    int coins[] = {15,10,6,3,1};
    for (int c: coins) {
        if (n == 12) {
            ans += 2;
            break;
        } else if (n + 15 == 23 and ans) {
            ans += 2;
            break;
        } else if (n + 15 == 20 and ans) {
            ans += 1;
            break;
        }
        ans += n/c;
        n %= c;
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}

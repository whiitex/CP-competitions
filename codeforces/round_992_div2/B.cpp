#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
    int n; cin >> n;

    if (n == 1) cout << 1 << '\n';
    else if (n <= 4) cout << 2 << '\n';
    else {
        int ans = 1, now = 1;
        while (now < n) {
            ++ans;
            now += now + 2;
        }
        cout << ans << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

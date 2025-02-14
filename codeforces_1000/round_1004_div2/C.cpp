#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;

const int INF = 1e18;

void solve() {
    int n; cin >> n;

    string s = to_string(n);
    for (char c: s) if (c == '7') { cout << 0 << '\n'; return; }

    vi ten(11, 1); for (int i=1; i<11; ++i) ten[i] = 10*ten[i-1];
    int ans = INF;
    for (int i=1; i<=10; ++i) {
        int add = 0, mask = i, j = 0;
        while (mask) {
            add += 9 * ten[j];
            mask -= 1; ++j;
        }

        int num = n;
        for (int q=1; q<=10; ++q) {
            num += add;
            s = to_string(num);
            for (char c: s) if (c == '7') {
                ans = min(ans, q);
                break;
            }
        }
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

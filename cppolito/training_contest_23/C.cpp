#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
    int n; cin >> n;
    vi vec(n); for (int &i: vec) cin >> i;

    if (n == 1) {
        cout << 2 << '\n';
        cout << vec[0] << ' ';
        cout << vec[0]*2 << '\n';
        return;
    }

    int sum = 0; for (int i: vec) sum += i;
    int xored = 0; for (int i: vec) xored ^= i;

    if (sum == 2 * xored) {
        cout << 0 << '\n'; return;
    }

    int two = 2;
    while (two <= (long long)1e17) two *= 2;

    cout << 3 << '\n';

    int add = two;
    if (sum & 1) ++add;
    cout << add << ' ';

    sum += add;
    xored ^= add;
    int ans2 = (xored*2 - sum) / 2;
    cout << ans2 << ' ' << ans2 << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}

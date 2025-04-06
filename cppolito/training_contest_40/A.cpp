#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef long double ld;
typedef vector<int> vi;

#define pb push_back

const ld EPS = 1e-9;

void solve() {
    ld r, h; cin >> r >> h;

    ld sq3r = sqrtl(3) * r / 2;;

    int tot = (h + r/2) / r;
    int ans = tot * 2;

    int H = tot * r;
    if (H + sq3r - EPS <= h + r) ++ans;

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();
}

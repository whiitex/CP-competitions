#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
    int n, a, b, c; cin >> n >> a >> b >> c;
    int tot = a+b+c;

    int ans = n / tot;
    n -= ans * tot;
    ans *= 3;

    if (n > 0) n -= a, ++ans;
    if (n > 0) n -= b, ++ans;
    if (n > 0) n -= c, ++ans;

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

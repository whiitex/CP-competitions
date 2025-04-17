#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;

#define pb push_back

void solve() {
    int n; cin >> n;
    vi a(n); for (int &i: a) cin >> i;

    sort(a.begin(), a.end());

    vi even, odd;
    for (int i: a) {
        if (i & 1) odd.pb(i);
        else even.pb(i);
    }

    if (even.empty() or odd.empty()) { cout << a[n-1] << '\n'; return; }

    int ans = 0; for (int i: even) ans += i;
    for (int i: odd) ans += i; ans -= odd.size() - 1;
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

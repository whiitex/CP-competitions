#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;


void solve() {
    int n; cin >> n;
    vi a(n); for (int &i: a) cin >> i;

    vi f(n+2); for (int i: a) ++f[i];

    for (int i=1; i<=n; ++i) {
        f[i+1] += max(0ll, f[i] - 2);
        if (f[i] == 1) { cout << "NO\n"; return; }
    }

    if (f[n+1] % 2 == 0) cout << "YES\n";
    else cout << "NO\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

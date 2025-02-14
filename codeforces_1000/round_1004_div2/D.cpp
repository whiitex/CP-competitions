#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;


void solve() {
    int n; cin >> n;
    vi a(n); for (int &i: a) cin >> i;

    auto ask = [&] (int x, int y) -> int {
        cout << "? " << x << ' ' << y << endl;
        int w; cin >> w; return w;
    };
    auto ans = [&] (char x) -> void {
        cout << "! " << x << endl;
    };

    vi f(n+1); for (int i: a) ++f[i];

    int miss = -1, thereis = 0;
    for (int i=1; i<=n; ++i) {
        if (!f[i]) miss = i;
        if (f[i]) thereis = i;
    }
    if (miss != -1) {
        int x = ask(miss, thereis);
        if (x == 0) ans('A');
        else ans('B');
        return;
    }

    int mn, mx;
    for (int i=0; i<n; ++i) {
        if (a[i] == 1) mn = i+1;
        if (a[i] == n) mx = i+1;
    }

    int x = ask(mn, mx);
    int y = ask(mx, mn);
    if (x == y and x >= n) ans('B');
    else if (x == 0 or y == 0 or x != y) ans('A');
    else if (x == y and x <= n/2) ans('A');
    else ans('B');
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

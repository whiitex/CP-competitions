#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
    int n; cin >> n;

    if (n & 1) cout << n << '\n';
    else {
        int a = n, b = 0, t = 1;
        while (a) {
            b += t;
            a >>= 1;
            t *= 2;
        }
        cout << b << '\n';
    }

    if (n == 5) { cout << "2 1 3 4 5\n"; return; }
    if (n == 6) { cout << "1 2 4 6 5 3\n"; return; }
    if (n == 7) { cout << "2 4 5 1 3 6 7\n"; return; }

    int ok = 0;
    if (n & 1) --n, ok = 1;

    int bit = 31 - __builtin_clz(n);
    int xr = (1 << bit) - 1;

    for (int i = (1<<bit)+1; i<=n; ++i) cout << i << ' ';
    for (int i=1; i<1<<bit-1; ++i) {
        int oth = i ^ xr;
        if (oth == 0) oth = 1 << bit;
        cout << i << ' ' << oth << ' ';
    }

    cout << xr << ' ' << xr + 1 << ' ';

    if (ok) cout << n+1;
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

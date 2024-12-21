#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef long double ld;

void solve() {
    ld d; cin >> d;

    if (d == 1) {cout << "N\n"; return; }
    if (d*d < 4*d) {cout << "N\n"; return; }

    ld b = (d + sqrt(d*d - 4*d)) / 2;

    if (b == 1) {cout << "N\n"; return; }

    ld a = b / (b-1);
    cout <<  setprecision(9) << fixed << "Y " << a << ' ' << b << '\n';
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}
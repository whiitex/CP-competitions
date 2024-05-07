#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll a, b;

bool ck(int x, int y, int xx, int yy) {
    if (x+a == xx and y+b == yy) return true;
    if (x+a == xx and y-b == yy) return true;
    if (x-a == xx and y+b == yy) return true;
    if (x-a == xx and y-b == yy) return true;

    if (x+b == xx and y+a == yy) return true;
    if (x+b == xx and y-a == yy) return true;
    if (x-b == xx and y+a == yy) return true;
    if (x-b == xx and y-a == yy) return true;

    return false;
}


void solve() {
    cin >> a >> b;
    ll kx, ky; cin >> kx >> ky;
    ll qx, qy; cin >> qx >> qy;

    int count = 0;

    if (ck(kx +a, ky+b, qx, qy)) count++;
    if (ck(kx +a, ky-b, qx, qy)) count++;
    if (ck(kx -a, ky+b, qx, qy)) count++;
    if (ck(kx -a, ky-b, qx, qy)) count++;
    if (a!= b) {
        if (ck(kx + b, ky + a, qx, qy)) count++;
        if (ck(kx + b, ky - a, qx, qy)) count++;
        if (ck(kx - b, ky + a, qx, qy)) count++;
        if (ck(kx - b, ky - a, qx, qy)) count++;
    }

    cout << count << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
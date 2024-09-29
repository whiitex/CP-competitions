#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
    int n, x, y; cin >> n >> x >> y;

    vi a(n, 1);
    for (int i=y-2; i>=0; i-=2) a[i] -=2;
    for (int i=x; i<n; i+=2) a[i] -= 2;
    for (int i: a) cout << i << ' ';
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

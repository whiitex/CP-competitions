#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n, a, b; cin >> n >> a >> b;

    cout << ( abs(a-b) % 2 == 0 ? "Yes\n" : "No\n");
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}
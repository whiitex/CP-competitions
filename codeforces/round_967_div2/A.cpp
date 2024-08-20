#include <bits/stdc++.h>

using namespace std;

#define int long long

typedef vector<int> vi;
void solve() {
    int n; cin >> n;
    vi vec(n); for (int &i: vec) cin >> i;

    vi rep(n+1);
    for (int i:vec) ++rep[i];
    int mx = 0;
    for (int i: rep) mx = max(mx, i);
    cout << n - mx << '\n';;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

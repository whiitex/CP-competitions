#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
    int n; cin >> n;
    vi vec(n); for (int &i: vec) cin >> i;

    int ans1 = 0, mx = 0;
    for (int i=0; i<n; i+=2) {
        mx = max(mx, vec[i]);
        ++ans1;
    }
    ans1 += mx;

    int ans2 = 0; mx = 0;
    for (int i=1; i<n; i+=2) {
        mx = max(mx, vec[i]);
        ++ans2;
    }
    ans2 += mx;

    cout << max(ans1, ans2) << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

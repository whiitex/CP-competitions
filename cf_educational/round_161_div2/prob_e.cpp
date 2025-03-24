#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

void solve() {
    ll x; cin >> x;
    vi vec;
    int mn = 0, mx = 1000;
    while (x > 1) {
        if (x & 1) {
            vec.push_back(mn);
            ++mn;
            --x;
        } else {
            vec.push_back(mx);
            --mx;
            x >>= 1;
        }
    }

    std::reverse(vec.begin(), vec.end());
    if (vec.size() > 200) {
        cout << -1 << '\n';
    } else {
        cout << vec.size() << '\n';
        for (int i: vec) cout << i << ' ';
        cout << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}

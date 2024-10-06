#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
    int n, q; cin >> n >> q;
    vi vec(n); for (int &i: vec) cin >> i;

    unordered_map<int, int> mp;
    for (int i=0; i<n-1; ++i) {
        int edges = (i+1) * (n-i-1);
        mp[edges] += vec[i+1] - 1 - vec[i];
        mp[edges + i] += 1;
    }
    mp[n-1] += 1;

    while (q--) {
        int k; cin >> k;
        cout << mp[k] << ' ';
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

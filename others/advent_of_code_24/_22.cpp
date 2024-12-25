#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

#define pb push_back

const int MOD = 16777216;

void solve() {
    int n = 2037;
    vi init(n); for (int &i: init) cin >> i;

    auto get_secret = [] (int x, int th=2000) {
        for (int i=0; i<th; ++i) {
            x = ((x << 6) ^ x) % MOD;
            x = ((x >> 5) ^ x) % MOD;
            x = ((x * 2048) ^ x) % MOD;
        } return x;
    };

    int ans1 = 0;
    for (int secret: init) {
        ans1 += get_secret(secret);
    }
    cout << "part 1: " << ans1 << '\n';

    vector change(n, vi()), value(n, vi());
    for (int i=0; i<n; ++i) {
        int x = init[i];
        for (int rep=0; rep<2000; ++rep) {
            int y = get_secret(x, 1);
            change[i].pb((y%10) - (x%10));
            value[i].pb(y%10);
            x = y;
        }
    }


    map<array<int,4>, int> mx;
    for (int i=0; i<n; ++i) {
        set<array<int,4>> done;
        for (int j=3; j<(int)change[i].size(); ++j) {
            array<int,4> pattern = {change[i][j-3], change[i][j-2], change[i][j-1], change[i][j]};
            if (!done.contains(pattern)) {
                mx[pattern] += value[i][j];
                done.insert(pattern);
            }
        }
    }

    int ans2 = 0;
    for (auto [pattern, val]: mx) ans2 = max(ans2, val);
    cout << "part 2: " << ans2 << '\n';
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();
}
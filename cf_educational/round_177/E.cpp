#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;

vi zebra;
map<pii,int> dp;

void solve() {
    int l, r, k; cin >> l >> r >> k;

    auto rec = [&] (auto f, int i, int j) -> int {
        if (dp.contains({i, j})) return dp[{i, j}];

        if (j < 0 or i <= 0) return dp[{i, j}] = 0;
        if (i == 1) return dp[{i, j}] = j == 0;

        int z = -(*upper_bound(zebra.begin(), zebra.end(), -i));
        return dp[{i, j}] = f(f, z, j) + f(f, i-z, j-1);
    };

    cout << rec(rec, r+1, k) - rec(rec, l, k) << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    for (int i=0, x=1; i<31; ++i) {
        zebra.push_back(-x);
        x <<= 2; ++x;
    }
    reverse(zebra.begin(), zebra.end());

    int t = 1; cin >> t;
    while (t--) solve();
}

#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;


void solve() {
    int n; cin >> n;
    string s, t; cin >> s >> t;
    vector<vi> grid(2, vi(n, 0));

    for (int i=0; i<n; ++i) if (s[i] == '.') grid[0][i] = 1;
    for (int i=0; i<n; ++i) if (t[i] == '.') grid[1][i] = 1;

    int ans = 0;
    for (int i=1; i<n-1; ++i) {
        if (grid[0][i] and grid[1][i] and !grid[1][i-1] and !grid[1][i+1] and (grid[0][i+1] and grid[0][i-1])) ++ans;
        if (grid[1][i] and grid[0][i] and !grid[0][i-1] and !grid[0][i+1] and (grid[1][i+1] and grid[1][i-1])) ++ans;
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

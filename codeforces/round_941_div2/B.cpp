#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

string solve() {
    int n, m; cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            cin >> grid[i][j];
        }
    }

    if (n == 1 and m == 1) return "Yes";
    if (n == 1) {
        if (grid[0][0] == grid[0][m-1]) return "Yes";
        else return "No";
    }
    if (m == 1) {
        if (grid[0][0] == grid[n-1][0]) return "Yes";
        else return "No";
    }
    if (grid[0][0] == grid[n-1][m-1] or grid[n-1][0] == grid[0][m-1]) return "Yes";
    
    bool wh1 = false;
    bool wh2 = false;
    bool wh3 = false;
    bool wh4 = false;
    for (int i=0; i<n; ++i) {
        if (grid[i][0] == 'W') wh1 = true;
        if (grid[i][m-1] == 'W') wh2 = true;
    }
    
    for (int i=0; i<m; ++i) {
        if (grid[0][i] == 'W') wh3 = true;
        if (grid[n-1][i] == 'W') wh4 = true;
    }

    bool bl1 = false;
    bool bl2 = false;
    bool bl3 = false;
    bool bl4 = false;
    for (int i=0; i<n; ++i) {
        if (grid[i][0] == 'B') bl1 = true;
        if (grid[i][m-1] == 'B') bl2 = true;
    }

    for (int i=0; i<m; ++i) {
        if (grid[0][i] == 'B') bl3 = true;
        if (grid[n-1][i] == 'B') bl4 = true;
    }

    if ((wh1 and wh2 and wh3 and wh4) or (bl1 and bl2 and bl3 and bl4)) return "Yes";
    else return "No";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) cout << solve() << '\n';
}

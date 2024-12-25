#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;

#define st first
#define nd second

void solve() {
    int n; cin >> n;
    vector<string> g(n);
    for (string &s: g) cin >> s;
    int m = g[0].size();

    auto search1 = [&] (pii start, pii move) -> int {
        string a = "XMAS";
        int mxx = start.st + move.st * 3;
        int mxy = start.nd + move.nd * 3;
        if (mxx < 0 or mxx >= m or mxy < 0 or mxy >= n) return 0;

        for (int i=0; i<4; ++i) {
            if (g[start.st + i*move.st][start.nd + i*move.nd] != a[i]) return 0;
            if (i == 3) return 1;
        }

        return 0;
    };

    auto search2 = [&] (int x, int y) -> int {
        if (g[x][y] != 'A') return 0;

        if (g[x+1][y+1] == 'M' and g[x-1][y-1] == 'S') {
            if (g[x-1][y+1] == 'M' and g[x+1][y-1] == 'S') return 1;
            if (g[x-1][y+1] == 'S' and g[x+1][y-1] == 'M') return 1;
        } else if (g[x+1][y+1] == 'S' and g[x-1][y-1] == 'M') {
            if (g[x-1][y+1] == 'M' and g[x+1][y-1] == 'S') return 1;
            if (g[x-1][y+1] == 'S' and g[x+1][y-1] == 'M') return 1;
        }
        return 0;
    };

    // int ans = 0;
    // for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) {
    //     for (int x: {-1, 0, 1}) for (int y: {-1, 0, 1}) {
    //         ans += search1({i, j}, {x, y});
    //     }
    // }

    int ans = 0;
    for (int i=1; i<n-1; ++i) for (int j=1; j<m-1; ++j) {
        ans += search2(i, j);
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();
}





















































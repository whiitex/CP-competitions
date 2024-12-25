#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;

#define st first
#define nd second

void solve() {
    int n; cin >> n;
    vector<string> g(n); for (auto &s : g) cin >> s;
    int m = g[0].size();


    auto isloop = [&] (int x, int y, int d) -> bool {
        vector vis(n, vi(m, 0));

        int loop = 0;
        while (true) {
            if (d == 1 and x-1 < 0) return 0;
            if (d == 2 and y+1 >= m) return 0;
            if (d == 3 and x+1 >= n) return 0;
            if (d == 4 and y-1 < 0) return 0;

            int turn = 0;
            if (d == 1 and g[x-1][y] == '#') d = 2, turn = 1;
            else if (d == 2 and g[x][y+1] == '#') d = 3, turn = 1;
            else if (d == 3 and g[x+1][y] == '#') d = 4, turn = 1;
            else if (d == 4 and g[x][y-1] == '#') d = 1, turn = 1;

            if (turn and vis[x][y] == 3) return 1;
            if (turn) { ++vis[x][y]; continue; }

            if (d == 1) --x;
            if (d == 2) ++y;
            if (d == 3) ++x;
            if (d == 4) --y;
        }
    };

    int x=0, y=0, d=0;
    // find starting position
    for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) {
        if (g[i][j] == '#' or g[i][j] == '.') continue;

        x = i; y = j;
        switch (g[i][j]) {
        case '^': d = 1; break;
        case '>': d = 2; break;
        case 'v': d = 3; break;
        case '<': d = 4; break;
        }
    } g[x][y] = d + '0';

    int ans = 0;
    // vector check(n, vi(m, 0));
    while (true) {
        if (d == 1 and x-1 < 0) break;
        if (d == 2 and y+1 >= m) break;
        if (d == 3 and x+1 >= n) break;
        if (d == 4 and y-1 < 0) break;

        int turn = 0;
        if (d == 1 and g[x-1][y] == '#') d = 2, turn = 1;
        else if (d == 2 and g[x][y+1] == '#') d = 3, turn = 1;
        else if (d == 3 and g[x+1][y] == '#') d = 4, turn = 1;
        else if (d == 4 and g[x][y-1] == '#') d = 1, turn = 1;
        if (turn) continue;


        switch (d) {
        case 1: {
            if (g[x-1][y] == '.') {
                g[x-1][y] = '#';
                ans += isloop(x, y, d);
                g[x-1][y] = '.';
            }
            break;
        }
        case 2: {
            if (g[x][y+1] == '.') {
                g[x][y+1] = '#';
                ans += isloop(x, y, d);
                g[x][y+1] = '.';
            }
            break;
        }
        case 3: {
            if (g[x+1][y] == '.') {
                g[x+1][y] = '#';
                ans += isloop(x, y, d);
                g[x+1][y] = '.';
            }
            break;
        }
        case 4: {
            if (g[x][y-1] == '.') {
                g[x][y-1] = '#';
                ans += isloop(x, y, d);
                g[x][y-1] = '.';
            }
            break;
        }
        }

        if (d == 1) --x;
        if (d == 2) ++y;
        if (d == 3) ++x;
        if (d == 4) --y;
        g[x][y] = 'X';
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();
}

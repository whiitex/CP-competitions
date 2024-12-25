#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

#define pb push_back
#define st first
#define nd second

const int INF = 1e18;

void solve() {
    int n; cin >> n;
    vector<string> g(n);
    for (int i=0; i<n; ++i) cin >> g[i];
    int m = (int)g[0].size();

    int xs=0, ys=0;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            if (g[i][j] == 'S') {
                xs = i, ys = j;
                break;
            }
        }
    } g[xs][ys] = '.';

    vector vis(n, vi(m, -2));
    auto dfs = [&] (auto f, int x, int y) -> int {
        if (g[x][y] == 'E') return vis[x][y] = 0;

        vis[x][y] = -1;
        for (int dx: {-1,0,1}) for (int dy: {-1,0,1}) if (!dx xor !dy) {
            if (vis[x+dx][y+dy] == -2 and g[x+dx][y+dy] != '#')
                vis[x][y] = f(f, x+dx, y+dy) + 1;
        }

        return vis[x][y];
    };

    dfs(dfs, xs, ys);
    cout << "No cheat: " << vis[xs][ys] << endl;


    int LIM1 = 12, cnt = 0;
    auto cheat = [&] (auto f, int x, int y) -> void {
        for (int dx: {-1,0,1}) for (int dy: {-1,0,1}) if (!dx xor !dy) {
            // try cheating
            if (g[x+dx][y+dy] == '#' and x+dx != 0 and x+dx != n-1 and y+dy != 0 and y+dy != m-1) {
                if (vis[x+ 2*dx][y + 2*dy] > -1 and vis[x][y] - vis[x+ 2*dx][y + 2*dy] > LIM1+1)
                    ++cnt;
            }
            // continue on the path
            if (vis[x+dx][y+dy] > -1 and vis[x+dx][y+dy] < vis[x][y])
                f(f, x+dx, y+dy);
        }

    };

    cheat(cheat, xs, ys);
    cout << "Cheat2 saves > " << LIM1-1 << ": " << cnt << endl;


    // part 2
    int CHEATS = 20, LIM2 = 100;
    auto cheat2 = [&] (int x, int y) -> int {
        vpii que;
        for (int dx=-CHEATS; dx<=CHEATS; ++dx) for (int dy=-CHEATS; dy<=CHEATS; ++dy) {
            if (abs(dx) + abs(dy) <= CHEATS and x+dx >= 0 and x+dx < n and y+dy >= 0 and y+dy < m)
                que.pb({x+dx, y+dy});
        }

        int count = 0;
        for (auto [xx, yy]: que) {
            int cheats = abs(x - xx) + abs(y - yy);
            int start = vis[x][y], end = vis[xx][yy];
            if (vis[xx][yy] > -1 and start - end - cheats >= LIM2) ++count;
        }
        return count;
    };


    int cnt2 = 0;
    for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) {
        if (g[i][j] == '.') {
            vector visit(n, vi(m, 0)); visit[i][j] = 1;
            cnt2 += cheat2(i, j);
        }
    }
    cout << "Cheat20 saves > " << LIM2-1 << ": " << cnt2 << endl;
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();
}

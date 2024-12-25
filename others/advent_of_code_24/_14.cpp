#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

const int INF = 1e18;

void solve() {
    int n; cin >> n;

    int w = 101, h = 103;
    vector quad(2, vi(2));

    vpii rob, vel;
    for (int i=0; i<n; ++i) {
        char c; cin >> c >> c;
        int x, y; cin >> x >> y;
        int vx, vy; cin >> c >> c >> vx >> vy;

        rob.push_back({x, y});
        vel.push_back({vx, vy});
    }

    vi times;
    for (int t=0; t<10000; ++t) {

        vector grid(w, vi(h));
        for (int i=0; i<n; ++i) {
            int x = rob[i].first, y = rob[i].second;
            int vx = vel[i].first, vy = vel[i].second;

            x = (x + t*vx) % w;
            y = (y + t*vy) % h;
            x = (x + w) % w;
            y = (y + h) % h;

            grid[x][y] = 1;
        }

        int mxseen = 0;
        vector vis(w, vi(h));
        auto dfs = [&] (auto f, int x, int y) -> int {
            int cnt = 1;
            for (int dx: {-1, 0, 1}) for (int dy: {-1, 0, 1}) {
                if (x+dx >= 0 and x+dx < w and y+dy >= 0 and y+dy < h) {
                    if (!vis[x+dx][y+dy] and grid[x+dx][y+dy]) {
                        vis[x+dx][y+dy] = 1;
                        cnt += f(f, x+dx, y+dy) + 1;
                    }
                }
            }
            return cnt;
        };

        for (int i=0; i<w; ++i) for (int j=0; j<h; ++j) if (!vis[i][j]) {
            mxseen = max(mxseen, dfs(dfs, i, j));
        }

        if (mxseen > 100) times.push_back(t);

        // if (x < w/2 and y < h/2) ++quad[0][0];
        // if (x < w/2 and y > h/2) ++quad[0][1];
        // if (x > w/2 and y < h/2) ++quad[1][0];
        // if (x > w/2 and y > h/2) ++quad[1][1];
    }

    for (int i: times) cout << i << ' ';
    // int ans = 1;
    // for (vi v: quad) for (int i: v) ans *= i;
    // cout << ans << '\n';
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();
}

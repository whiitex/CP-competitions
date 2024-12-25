#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

#define pb push_back

const int INF = 1e18;

void solve() {
    int n; cin >> n;
    vector<string> g(n);
    for (string &s: g) cin >> s;
    int m = (int)g[0].size();

    g[1][m-2] = '.';

    // data-structures
    priority_queue<array<int,3>, vector<array<int,3>>, greater<>> pq;
    vector dp(n, vector<array<int, 4>>(m, {INF,INF,INF,INF}));
    vector get(n, vector<array<int, 4>>(m, {INF,INF,INF,INF}));

    // init
    dp[n-2][1][1] = 0;
    pq.push({0, n-2, 1});
    get[n-2][1][1] = 0;

    // dijskstra
    while (!pq.empty()) {
        auto [_, x, y] = pq.top(); pq.pop();

        int mndir = INF; for (auto dir: dp[x][y]) mndir = min(mndir, dir);

        // up
        get[x-1][y][0] = min(get[x-1][y][0], min(dp[x][y][0], mndir + 1000));
        if (g[x-1][y] == '.' and dp[x-1][y][0] > min(dp[x][y][0] + 1, mndir + 1001)) {
            dp[x-1][y][0] = min(dp[x][y][0] + 1, mndir + 1001);
            pq.push({dp[x-1][y][0], x-1, y});
        }

        // right
        get[x][y+1][1] = min(get[x][y+1][1], min(dp[x][y][1], mndir + 1000));
        if (g[x][y+1] == '.' and dp[x][y+1][1] > min(dp[x][y][1] + 1, mndir + 1001)) {
            dp[x][y+1][1] = min(dp[x][y][1] + 1, mndir + 1001);
            pq.push({dp[x][y+1][1], x, y+1});
        }

        // down
        get[x+1][y][2] = min(get[x+1][y][2], min(dp[x][y][2], mndir + 1000));
        if (g[x+1][y] == '.' and dp[x+1][y][2] > min(dp[x+1][y][2] + 1, mndir + 1001)) {
            dp[x+1][y][2] = min(dp[x][y][2] + 1, mndir + 1001);
            pq.push({dp[x+1][y][2], x+1, y});
        }

        // left
        get[x][y-1][3] = min(get[x][y-1][3], min(dp[x][y][3], mndir + 1000));
        if (g[x][y-1] == '.' and dp[x][y-1][3] > min(dp[x][y][3] + 1, mndir + 1001)) {
            dp[x][y-1][3] = min(dp[x][y][3] + 1, mndir + 1001);
            pq.push({dp[x][y-1][3], x, y-1});
        }
    }

    int mnscore = INF;
    for (int i: dp[1][m-2]) mnscore = min(mnscore, i);
    cout << mnscore << '\n';

    vector vis(n, vi(m));
    auto get_dxdy = [] (int dir) -> pii {
        if (dir == 0) return {-1, 0};
        if (dir == 1) return {0, 1};
        if (dir == 2) return {1, 0};
        return {0, -1};
    };

    set<int> pars; pars.insert(1000 + m-2);
    auto dfs = [&] (auto f, int x, int y, int dir) -> bool {
        if (get[x][y][dir] > mnscore) return false;
        if (x == 1 and y == m-2) return true;

        // DIR -> 0: up, 1: right, 2: down, 3: left

        bool ok = false;
        {
            auto [dx, dy] = get_dxdy(dir);
            if (g[x+dx][y+dy] == '.' and get[x+dx][y+dy][dir] == dp[x][y][dir]) {
                ok |= f(f, x+dx, y+dy, dir);
            }
        }

        for (int d: {(dir+1) % 4, (dir+3) % 4}) {
            auto [dx, dy] = get_dxdy(d);
            if (g[x+dx][y+dy] == '.' and get[x+dx][y+dy][d] == dp[x][y][dir] + 1000) {
                ok |= f(f, x+dx, y+dy, d);
            }
        }

        if (ok) pars.insert(x*1000 + y);
        return ok;
    };

    dfs(dfs, n-2, 1, 1);
    cout << pars.size() << '\n';
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();
}

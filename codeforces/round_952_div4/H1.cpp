#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;

#define pb push_back
#define f first
#define s second

void solve() {
    int n, m; cin >> n >> m;
    vector<string> grid;
    for (int i=0; i<n; ++i) {
        string s; cin >> s;
        grid.pb(s);
    }

    int color = 0;
    vi colors(1);
    vector<vi> visited(n, vi(m, 0));
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            if (visited[i][j] or grid[i][j] == '.') continue;

            ++color;
            colors.pb(0);
            queue<pii> q; q.push({i, j});
            while (!q.empty()) {
                int x = q.front().f;
                int y = q.front().s;
                q.pop();

                if (visited[x][y]) continue;
                visited[x][y] = color;
                ++colors[color];

                if (x > 0 and !visited[x-1][y] and grid[x-1][y] == '#') q.push({x-1, y});
                if (x < n-1 and !visited[x+1][y] and grid[x+1][y] == '#') q.push({x+1, y});
                if (y > 0 and !visited[x][y-1] and grid[x][y-1] == '#') q.push({x, y-1});
                if (y < m-1 and !visited[x][y+1] and grid[x][y+1] == '#') q.push({x, y+1});
            }
        }
    }

    int ans = 0;
    for (int i=0; i<n; ++i) {
        int sum = 0;
        set<int> c;
        for (int j=0; j<m; ++j) {
            if (grid[i][j] == '.') ++sum;
            else if (grid[i][j] == '#' and !c.contains(visited[i][j])) {
                c.insert(visited[i][j]);
                sum += colors[visited[i][j]];
            }

            if (i > 0 and grid[i-1][j] == '#' and !c.contains(visited[i-1][j])) {
                c.insert(visited[i-1][j]);
                sum += colors[visited[i-1][j]];
            }

            if (i < n-1 and grid[i+1][j] == '#' and !c.contains(visited[i+1][j])) {
                c.insert(visited[i+1][j]);
                sum += colors[visited[i+1][j]];
            }
        }
        ans = max(ans, sum);
    }


    for (int i=0; i<m; ++i) {
        int sum = 0;
        set<int> c;
        for (int j=0; j<n; ++j) {
            if (grid[j][i] == '.') ++sum;
            else if (grid[j][i] == '#' and !c.contains(visited[j][i])) {
                c.insert(visited[j][i]);
                sum += colors[visited[j][i]];
            }

            if (i > 0 and grid[j][i-1] == '#' and !c.contains(visited[j][i-1])) {
                c.insert(visited[j][i-1]);
                sum += colors[visited[j][i-1]];
            }

            if (i < m-1 and grid[j][i+1] == '#' and !c.contains(visited[j][i+1])) {
                c.insert(visited[j][i+1]);
                sum += colors[visited[j][i+1]];
            }
        }
        ans = max(ans, sum);
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

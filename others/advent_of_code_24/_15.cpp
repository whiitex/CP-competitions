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

    string path = "<vv<<^^<<^^";

    vector<string> G(n);
    for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) {
        switch (g[i][j]) {
        case '.': G[i].pb('.'); G[i].pb('.'); break;
        case '#': G[i].pb('#'); G[i].pb('#'); break;
        case '@': G[i].pb('@'); G[i].pb('.'); break;
        case 'O': G[i].pb('['); G[i].pb(']'); break;
        default: cout << "Error\n"; return;
        }
    } m*=2;


    auto mvy = [&G] (int x, int Y, int dy) -> int {
        int y = Y + dy;
        while (G[x][y] == '[' or G[x][y] == ']') y += dy;

        if (G[x][y] == '#') return -1;
        while (y != Y) {
            swap(G[x][y], G[x][y-dy]);
            y -= dy;
        }
        return 1;
    };

    auto checkmvx = [&G] (auto f, int x, int y, int dx) -> bool {
        if (G[x][y] == '.') return true;

        int y1 = y;
        if (G[x][y] == '[') ++y1;
        if (G[x][y] == ']') --y1;

        if (G[x+dx][y] == '#' or G[x+dx][y1] == '#') return false;

        bool ans = true;
        ans &= f(f, x+dx, y, dx);
        ans &= f(f, x+dx, y1, dx);
        return ans;
    };

    auto shiftx = [&G] (auto f, int x, int y, int dx) -> void {
        if (G[x][y] == '.') return;

        int y1 = y;
        if (G[x][y] == '[') ++y1;
        if (G[x][y] == ']') --y1;

        if (G[x+dx][y] != '.' or G[x+dx][y1] != '.') {
            f(f, x+dx, y, dx);
            f(f, x+dx, y1, dx);
        }

        swap(G[x][y], G[x+dx][y]);
        swap(G[x][y1], G[x+dx][y1]);
    };

    int x=0, y=0;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            if (G[i][j] == '@') {
                x = i; y = j;
                break;
            }
        }
    } G[x][y] = '.';

    for (char c: path) {
        int dx=0, dy=0;
        switch (c) {
        case '>': dy = 1; break;
        case '^': dx = -1; break;
        case '<': dy = -1; break;
        case 'v': dx = 1; break;
        default: cout << "Error\n"; return;
        }

        if (G[x+dx][y+dy] == '#') continue;
        if (G[x+dx][y+dy] == '.') {
            x += dx; y+= dy;
            continue;
        }

        if (dx == 0) {
            if (mvy(x, y+dy, dy) == -1) continue;
            y += dy;
        } else if (checkmvx(checkmvx, x+dx, y, dx)) {
            shiftx(shiftx, x+dx, y, dx);
            x += dx;
        }
    }

    int ans = 0;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            if (G[i][j] == '[') ans += 100*i + j;
        }
    }

    for (string s: G) cout << s << '\n';
    cout << ans << '\n';

}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();
}
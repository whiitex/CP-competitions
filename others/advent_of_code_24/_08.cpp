#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

#define st first
#define nd second


void solve() {
    int n; cin >> n;
    vector<string> grid(n);
    for (auto &s: grid) cin >> s;
    int m = grid[0].size();

    set<pii> busy, antinode;
    vector lst(256, vpii());
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) if (grid[i][j] != '.') {
            // busy.insert({i, j});
            lst[(int)grid[i][j]].push_back({i, j});
        }
    }

    for (int ch=0; ch<256; ++ch) if (lst[ch].size() > 1) {
        vpii vec = lst[ch];

        for (int i=0; i<vec.size(); ++i) {
            antinode.insert(vec[i]);
            for (int j=0; j<vec.size(); ++j) if (i != j) {
                int dy = vec[j].nd - vec[i].nd;
                int dx = vec[j].st - vec[i].st;

                pii now = vec[i];
                while (now.st + dx >= 0 and now.st + dx < n and now.nd + dy >= 0 and now.nd + dy < m) {
                    now.st += dx;
                    now.nd += dy;
                    antinode.insert(now);
                }
            }
        }
    }

    cout << antinode.size() << '\n';
    // for (auto [x,y]: antinode) grid[x][y] = '#';
    // for (auto s: grid) cout << s << '\n';
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();
}



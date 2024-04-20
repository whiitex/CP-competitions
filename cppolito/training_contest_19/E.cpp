#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;

#define f first
#define s second

void solve() {
    int n, m, a; cin >> n >> m;

    vector<vector<char>> all(n, vector<char>(m));
    map<string, int32_t> mp;

    for (int i=0; i<n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a;
            all[i][j] = char(a);
        }
    }

    for (int i=0; i<n; ++i) {
        vector<pair<char, int>> v;
        for (int x=0; x<m; ++x) v.emplace_back(all[i][x], x+1);
        std::sort(v.begin(), v.end());

        string s;
        for (int j=0; j<m; ++j) {
            s.push_back(char(v[j].s));
            ++mp[s];
        }
    }

    for (int i=0; i<n; ++i) {

        int ans = 0;
        string s; s.push_back(all[i][0]);
        while (mp[s] and ans < m) {
            ++ans;
            s.push_back(all[i][ans]);
        }
        cout << ans << ' ';
    }

    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}

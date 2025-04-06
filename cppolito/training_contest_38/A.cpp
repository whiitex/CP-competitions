#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

#define pb push_back

const int MAXN = 5e5 + 5;

void solve() {
    int q; cin >> q;

    vector<array<int,3>> query;
    unordered_map<int,int> mp;
    vi ans;

    while (q--) {
        int op; cin >> op;

        if (op == 1) {
            int x; cin >> x;
            query.pb({1, x, 0});
        } else {
            int x, y; cin >> x >> y;
            query.pb({2, x, y});
        }
    }

    reverse(query.begin(), query.end());
    for (auto [op, x, y]: query) {
        if (op == 1) {
            if (mp[x]) ans.pb(mp[x]);
            else ans.pb(x);
        } else {
            if (mp[y]) mp[x] = mp[y];
            else mp[x] = y;
        }
    }

    reverse(ans.begin(), ans.end());
    for (int i: ans) cout << i << ' ';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();
}

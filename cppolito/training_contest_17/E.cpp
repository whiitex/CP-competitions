#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

void solve() {
    int n; cin >> n;
    vll cost(n+1); vi next(n+1);
    for (int i=1; i<=n; ++i) cin >> cost[i];
    for (int i=1; i<=n; ++i) cin >> next[i];

    vector<bool> visited(n+1, 0);
    ll toadd;
    auto dfs = [&] (auto self, int node, set<int>& st) -> int {

        int loop;
        if (not visited[node]) {
            visited[node] = 1;
            st.insert(node);
            loop = self(self, next[node], st);

        } else if (st.count(node)) {
            toadd = min(toadd, cost[node]);
            return node;
        } else return 0;

        if (loop == 0) return 0;

        if (node == loop) return 0;

        toadd = min(toadd, cost[node]);
        return loop;
    };

    ll ans = 0;
    for (int i=1; i<=n; ++i) {
        toadd = (int)1e6;
        set<int> _set;
        dfs(dfs, i, _set);
        if (toadd < (int)1e6) ans += toadd;
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}

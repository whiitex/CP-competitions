#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;

#define st first
#define nd second

void solve() {
    int n; cin >> n;
    vi a(n); for (int &i: a) cin >> i;

    vi nxt(a);
    sort(nxt.begin(), nxt.end(), greater<>());

    map<int,set<int>> pos;
    for (int i=0; i<n; ++i) pos[a[i]].insert(i);

    int ans = 0;
    set<pii> avail; vi vis(n);

    for (int x: nxt) {

        auto it = avail.lower_bound({x, 0});
        if (it == avail.end() or it->st != x) {
            int p = *pos[x].begin();
            avail.insert({x, p});
            ++ans;
        }

        it = avail.lower_bound({x, 0});
        int p = it->nd;
        avail.erase(it);
        vis[p] = 1;
        if (p and !vis[p-1]) avail.insert({a[p-1], p-1});
        if (p < n-1 and !vis[p+1]) avail.insert({a[p+1], p+1});

        pos[x].erase(p);
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

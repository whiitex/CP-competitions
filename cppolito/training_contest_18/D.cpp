#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    set<int> pers; int l=0, r=0;

    for (int i=0; i<n; ++i) {
        int a; cin >> a;
        if (a == -1) ++l;
        else if (a == -2) ++r;
        else pers.insert(a);
    }

    int ans = min(max(l,r) + (int)pers.size(), m);

    int tak = 0, ps = pers.size();
    for (int p: pers) {
        int left = min(1+tak+l, p);
        int right = min(ps-tak-1 + r, m-p);
        ans = max(ans, left + right);
        ++tak;
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}

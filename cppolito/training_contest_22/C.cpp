#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
    int n, m; cin >> n >> m;
    vi stak(n); for (int &i: stak) cin >> i;
    vi lst(m); for (int &i: lst) cin >> i;

    int ans = 0, j = 0;
    set<int> found;
    for (int i=0; i<m; ++i) {
        if (found.find(lst[i]) != found.end()) {
            ++ans; continue;
        }

        while (stak[j] != lst[i]) {
            found.insert(stak[j]); ++j;
        } ++j;

        ans += (j-i-1) * 2 + 1;
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}

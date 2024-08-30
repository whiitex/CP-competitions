#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n, m; cin >> n >> m;
    set<int> st;
    for (int i=0; i<n; ++i) {
        int z; cin >> z;
        st.insert(z);
    }

    int mx = *st.rbegin();

    while (m--) {
        char c; int l, r; cin >> c >> l >> r;
        if (c == '+' and r >= mx and l <= mx) ++mx;
        else if (c == '-' and r >= mx and l <= mx) --mx;

        cout << mx << ' ';
    }

    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

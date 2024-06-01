#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

#define pb push_back

void solve() {
    int n, k; cin >> n >> k;
    vector<vi> vec(n, vi(k));
    for (int i=0; i<n; ++i) {
        for (int j=0; j<k; ++j)
            cin >> vec[i][j];
    }

    int ans = 0;
    for (int i=0; i<n; ++i) {
        set<string> st;
        int count = 0;

        for (int j=0; j<n; ++j) {
            if (j == i) continue;
            string to_put, to_find;

            for (int v=0; v<k; ++v) {
                int val = vec[j][v];
                to_find.pb('0' + val);

                if (val == vec[i][v]) to_put.pb(val + '0');
                else {
                    int q = 0;
                    while (q == val or q == vec[i][v]) ++q;
                    to_put.pb(q + '0');
                }
            }

            if (st.find(to_find) != st.end()) ++count;
            st.insert(to_put);
        }

        if (count) ans += (count-1) * count / 2;
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1; // cin >> t;
    while (t--) solve();
}

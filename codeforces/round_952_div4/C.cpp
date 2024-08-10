#include <bits/stdc++.h>

using namespace std;

#define int long long

typedef vector<int> vi;

void solve() {
    int n; cin >> n;
    vi vec(n); for (int &i: vec) cin >> i;

    int ans = 0, pref = 0;
    set<int> st; st.insert(0);
    for (int i: vec) {
        pref += i;
        st.insert(i);
        if (pref % 2 == 0 and st.contains(pref/ 2)) ++ans;
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

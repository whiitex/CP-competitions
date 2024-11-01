#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
    int n; cin >> n;
    vi vec(n); for (int &i: vec) cin >> i;

    sort(vec.begin(), vec.end());

    set<int> st; for (int i: vec) st.insert(i);
    if (st.size() == 1) {cout << 0 << '\n'; return; }

    map<int,int> suff, freq;
    for (int i=n-1, sm=0; i>=0; --i) {
        ++sm; suff[vec[i]] = sm;
        ++freq[vec[i]];
    }

    int ans = n - freq[vec[n-1]]-1;
    for (int i=0; i<n-1; ++i) {
        int sm = vec[i] + vec[i+1];
        int sub = sm > vec[n-1] ? 0 : suff[*st.lower_bound(sm)];
        ans = min(ans, i + sub);
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

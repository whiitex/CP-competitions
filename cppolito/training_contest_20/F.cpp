#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
    int n; cin >> n;
    vi vec(n); for(int& i: vec) cin >> i;

    set<array<int,3>> st;

    vector<array<int,3>> left(n);
    st.insert({vec[0] - n, vec[0], 0});
    for (int i = 1; i < n - 1; ++i) {
        left[i] = *st.rbegin();
        st.insert({vec[i] - (n - i), vec[i], i});
    }

    st.clear();

    vector<array<int,3>> right(n);
    st.insert({vec[n-1] - n, vec[n-1], n-1});
    for (int i=n-2; i>0; --i) {
        right[i] = *st.rbegin();
        st.insert({vec[i]- (i+1), vec[i], i});
    }


    int ans = 1;
    for (int i=1; i<n-1; ++i) {
        int top3 = vec[i] + left[i][1] + right[i][1];
        int dist = right[i][2] - left[i][2];
        ans = max(ans, top3 - dist);
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}

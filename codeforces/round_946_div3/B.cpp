#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
    int n; cin >> n;
    string p; cin >> p;
    string r;

    set<char> st;
    for (char c: p) st.insert(c);
    for (char c: st) r.push_back(c);
    int m = r.size();

    map<char,int> mp;
    for (int i=0; i<m; ++i) {
        mp.insert({r[i], i});
    }

    string ans;
    for (char c: p) {
        int ind = mp[c];
            ans.push_back(r[m-1-ind]);
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}

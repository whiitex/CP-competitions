#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    int n, ans = 0; cin >> n;
    string s; cin >> s;
    bool can = true;
    for  (int i=0; i<n && can; ++i) {
        if (s[i] == '@') ++ans;
        else if (s[i] == '*' and s[min(i+1,n-1)] == '*') can = false;
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}

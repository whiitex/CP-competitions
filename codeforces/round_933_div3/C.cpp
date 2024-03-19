#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    int ans = 0;
    for (int i=0; i<n-2; ++i) {
        if (s[i] == 'p' and s[i+1] == 'i' and s[i+2] == 'e') {
            ++ans;
            i+=2;
        } else if (s[i] == 'm' and s[i+1] == 'a' and s[i+2] == 'p') {
            ++ans;
            i+=2;
        }
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

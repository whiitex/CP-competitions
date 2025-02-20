#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;


void solve() {
    string s; cin >> s;
    int n = (int)s.size();

    string a;
    {
        int j = 0;
        while (j < n/2 and s[j] == s[n-j-1]) ++j;

        a = s.substr(j, n-2*j);
        n -= j*2;
    }

    if (n == 0) { cout << 0 << '\n'; return; }

    int ans = n-1;
    vector dx(27, vi(n)), sx(27, vi(n));
    for (int i=0; i<n; ++i) {
        ++sx[a[i]-'a'][i];
        if (i) for (int j=0; j<26; ++j) sx[j][i] += sx[j][i-1];
    }
    for (int i=n-1; i>=0; --i) {
        ++dx[a[i]-'a'][i];
        if (i < n-1) for (int j=0; j<26; ++j) dx[j][i] += dx[j][i+1];
    }

    for (int len = n-2; len > 1; --len) {
        if (len < n/2 and a[len] != a[n-len-1]) break;

        // shuffle sx
        int ok = 1;
        for (int c=0; c<27; ++c) {
            if (sx[c][len-1] < dx[c][max(len, n-len)]) ok = 0;
        } if (ok) ans = len;

        // shuffle dx
        ok = 1;
        for (int c=0; c<27; ++c) {
            if (dx[c][n-len] < sx[c][min(len-1, n-len-1)]) ok = 0;
        } if (ok) ans = len;
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

#define pb push_back

void solve() {
    int n; cin >> n;
    vi vec(n); for (int &i: vec) cin >> i;
    vi pref(n, vec[0]); for (int i=1; i<n; ++i) pref[i] = pref[i-1] + vec[i];
    string s; cin >> s;

    int ans = 0;
    vi l, r;
    for (int i=0; i<n; ++i) if (s[i] == 'L') l.pb(i);
    for (int i=n-1; i>=0; --i) if (s[i] == 'R') r.pb(i);

    for (int i=0; i<n; ++i) {
        if (i >= min(l.size(), r.size())) break;
        if (r[i] > l[i]) {
            ans += pref[r[i]];
            if (l[i]) ans -= pref[l[i]-1];
        }
    }


    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

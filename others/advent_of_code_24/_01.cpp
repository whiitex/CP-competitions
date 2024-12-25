#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;

#define st first
#define nd second

void solve() {
    int n; cin >> n;
    vi l(n), r(n);
    for (int i=0; i<n; i++) cin >> l[i] >> r[i];

    // sort(l.begin(), l.end());
    // sort(r.begin(), r.end());
    //
    // int ans = 0;
    // for (int i=0; i<n; ++i) ans += abs(r[i] - l[i]);
    // cout << ans << '\n';

    unordered_map<int,int> mp;
    for (int i: r) ++mp[i];

    int ans = 0;
    for (int i: l) {
        ans += i * mp[i];
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();
}
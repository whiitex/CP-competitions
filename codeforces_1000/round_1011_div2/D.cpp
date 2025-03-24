#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
    int n, k; cin >> n >> k;
    vi a(n); for (int &i: a) cin >> i;

    vi take(n); for (int i=n-k-1; i>=0; i-=k+1) {
        take[i] =1;
    }

    multiset<int> ms; int ans = 0;
    for (int i=0; i<n; ++i) {
        ms.insert(a[i]);
        if (take[i]) {
            ans += *ms.rbegin();
            ms.erase(--ms.end());
        }
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}

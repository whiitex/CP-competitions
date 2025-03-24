#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

#define pb push_back

void solve() {
    int n; cin >> n;
    vi a(n); for (int &i: a) cin >> i;

    vpii ans;

    if (a[0] == 0) {
        vi b; b.pb(a[1] == 1 ? 2 : 1);
        for (int i=2; i<n; ++i) b.pb(a[i]);
        --n; a = b; ans.pb({1, 2});
    }

    if (a[n-1] == 0) {
        vi b; for (int i=0; i<n-2; ++i) b.pb(a[i]);
        b.pb(a[n-2] == 1 ? 2 : 1);
        --n; a = b; ans.pb({n, n + 1});
    }


    int last = 1;
    for (int i=1; i<n; ++i) {
        if (a[i] == 0) {
            ans.pb({last, last + 1});
        } else ++last;
    }

    if (last > 1) ans.pb({1, last});

    cout << ans.size() << '\n';
    for (auto [q, w]: ans) cout << q << ' ' << w << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

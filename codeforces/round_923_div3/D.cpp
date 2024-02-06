#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vpii;

#define f first
#define s second

void solve() {
    int n; cin >> n;
    vpii a(n);
    for (int i=0; i<n; ++i) cin >> a[i].f;

    // build
    for (int i=0; i<n; ++i) {
        int j=i+1;
        while (j<n and a[j].f == a[j-1].f)
            ++j;

        for (int k=i; k<j; ++k)
            a[k].s = j;

        i = j-1;
    }

    int q, l, r; cin >> q;
    for (int i=0; i<q; ++i) {
        cin >> l >> r; --l; --r;

        if (a[l].s <= r) cout << l+1 << ' ' << a[l].s+1 << '\n';
        else cout << "-1 -1\n";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}

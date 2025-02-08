#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

#define pb push_back

const int INF = 1e18;

void solve() {
    int n; cin >> n;
    vi a(n); for (int &i: a) cin >> i;

    map<int,int> f; for (int i: a) ++f[i];
    for (auto [l, freq]: f) if (freq > 3) {
        for (int i=0; i<4; ++i) cout << l << ' ';
        cout << '\n'; return;
    }

    int l1 = -1, done1 = 0;
    for (auto [l, freq]: f) {
        if (freq > 1 and !done1) { l1 = l; done1 = 1; }
        else if (freq > 1) {
            cout << l << ' ' << l << ' ';
            cout << l1 << ' ' << l1 << ' ';
            cout << '\n'; return;
        }
    }

    int mxl = -INF;
    for (auto [l, freq]: f) if (freq > 1) mxl = max(mxl, l);

    int rem = 0;
    vi s;
    for (int i=0; i<n; ++i) {
        if (mxl == a[i] and rem < 2) ++rem;
        else s.pb(a[i]);
    }
    sort(s.begin(), s.end());

    for (int i=1; i<n-2; ++i) {
        int la = s[i-1], lb = s[i];
        if (lb - la < 2*mxl) {
            cout << mxl << ' ' << mxl << ' ';
            cout << la << ' ' << lb << ' ';
            cout << '\n'; return;
        }
    }


    cout << -1 << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

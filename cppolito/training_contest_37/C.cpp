#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

#define all(a) a.begin(), a.end()

const int MAXN = 2e5+1;

void solve() {
    int n, k; cin >> n >> k;
    vector odd(MAXN, vi()), even(MAXN, vi());
    for (int i=0; i<n; ++i) {
        int a; cin >> a;
        if (i & 1) odd[a].push_back(i);
        else even[a].push_back(i);
    }
    if (k == 1) { cout << 0; return; }

    int good = 0;
    for (auto vec: { odd, even}) {
        for (vi &v: vec) if (v.size() > 1) {

            int R=0, back = 0;
            for (int i=0; i<v.size()-1; ++i) {
                int x = v[i];
                int lo = max(x+2, k-1-x);
                int hi = min(x+k-1, 2*n-1-k-x);

                if (lo > hi) continue;
                good += upper_bound(all(v), hi) - lower_bound(all(v), lo);
            }

        } // 1 1 1 2 1 1 1 1
    }

    int tot = (k/2) * (n-k+1);
    cout << tot - good << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; // cin >> t;
    while (t--) solve();
}
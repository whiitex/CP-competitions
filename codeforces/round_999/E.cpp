#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;

#define pb push_back
const int INF = 1e18;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vi a(n); for (int &i: a) cin >> i;
    vi b(m); for (int &i: b) cin >> i;

    vi all(m*n); int allp = 0;
    for (int i=0; i<n; ++i) {
        vi add(m+1, a[i]);
        for (int mask=0; mask<(1<<m); ++mask) {
            int num = a[i], ops = 0;
            for (int bit=0; bit<m; ++bit) {
                if ((mask >> bit) & 1) num &= b[bit], ++ops;
            }

            add[ops] = min(add[ops], num);
        }

        for (int j=m; j>0; --j) add[j] = add[j-1] - add[j];
        for (int j=1; j<=m; ++j) all[allp+j-1] = add[j];
        allp += m;
    }

    sort(all.begin(), all.end(), greater<>());

    int ans = 0; for (int i: a) ans += i;
    for (int i=0; i<k; ++i) ans -= all[i];
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

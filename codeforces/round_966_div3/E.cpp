#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

#define pb push_back

void solve() {
    int n, m, k, w; cin >> n >> m >> k >> w;
    vi vec(w); for (int &i: vec) cin >> i;

    vi mul;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            int l = min(j, k-1), r = min(m - j - 1, k-1);
            int t = min(i, k-1), d = min(n - i - 1, k-1);

            int wi = r + l + 1;
            int h = t + d + 1;
            mul.pb((wi-k+1) * (h-k+1));
        }
    }

    sort(vec.begin(), vec.end(), greater());
    sort(mul.begin(), mul.end(), greater());

    int ans = 0;
    for (int i=0; i<w; ++i) ans += vec[i] * mul[i];

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vi f(n); for (int & i: f) cin >> i;
        vi h(n); for (int & i: h) cin >> i;

        int ans = 0;
        for (int i: f) if (i <= k) ans = 1;

        for (int i=0; i<n-1; ++i) {
            int l=i; ll count = f[i];
            while (i<n-1 and h[i] % h[i+1] == 0) {
                count += f[i+1];

                while (count > k) count -= f[l++];

                ++i;
                ans = max(ans, i-l+1);
            }
        }

        cout << ans << '\n';
    }
}

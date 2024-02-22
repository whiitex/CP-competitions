#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vi vec(n); for (int &i: vec) cin >> i;
        std::sort(vec.begin(), vec.end());

        vi dp(n+1, 0);
        for (int i=0; i<n; ++i) {
            int j = i, num = vec[i];
            while (i<n-1 and vec[i] == vec[i+1]) ++i;
            int count = i-j+1;

            for (int x=num; x <= n; x+=num) dp[x] += count;
        }

        int mx = -1;
        for (int i: dp) mx = max(mx, i);
        cout << mx << '\n';
    }
}

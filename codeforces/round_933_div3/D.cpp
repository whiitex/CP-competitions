#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {

        int n, m, x;
        cin >> n >> m >> x;
        int dp[m + 1][n];
        memset(dp, 0, sizeof(dp));

        dp[0][x - 1] = 1;
        for (int i = 0; i < m; ++i) {
            int dist;
            cin >> dist;
            char cc;
            cin >> cc;
            for (int p = 0; p < n; ++p) {
                if (dp[i][p] == 0) continue;

                if (cc == '0') dp[i + 1][(p + dist) % n] = 1;
                else if (cc == '1') {
                    int pp = (p - dist + n) % n;
                    dp[i + 1][pp] = 1;
                } else {
                    dp[i + 1][(p + dist) % n] = 1;
                    int pp = (p - dist + n) % n;
                    dp[i + 1][pp] = 1;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) if (dp[m][i]) ++ans;

        cout << ans << '\n';
        for (int i = 0; i < n; ++i) {
            if (dp[m][i]) cout << i + 1 << ' ';
        }
        cout << '\n';

    }
}

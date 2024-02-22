#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        string grid[10];
        for (string& s: grid) cin >> s;

        int ans = 0;
        for (int x=0; x<5; ++x)
            for (int i = x; i < 10-x; ++i)
                for (int j = x; j < 10-x; ++j)
                    if (grid[i][j] == 'X') ++ans;

        cout << ans << '\n';
    }
}

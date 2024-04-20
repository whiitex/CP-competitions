#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
typedef vector<int> vi;

int matrix[100][100], n , m;
bool ck[100][100];
bool check(int x) {
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            ck[i][j] = matrix[i][j] % x == 0;
        }
    }

    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            if (i == 0 and j) ck[i][j] = ck[i][j] and ck[i][j-1];
            else if (j == 0 and i) ck[i][j] = ck[i][j] and ck[i-1][j];
            else if (i and j) ck[i][j] = ck[i][j] and (ck[i-1][j] or ck[i][j-1]);
        }
    }

    return ck[n-1][m-1];
}

void solve() {
    cin >> n >> m;

    for (int i=0; i<n; ++i)
        for (int j=0; j<m; ++j)
            cin >> matrix[i][j];

    int gcd = __gcd(matrix[0][0], matrix[n-1][m-1]);
    int sq = (int) sqrt(gcd) + 1, ans = 1;

    for (int i=1; i<=sq; ++i) {
        if (gcd % i == 0) {
            if (check(i)) ans = max(ans, i);
            if (check(gcd/i)) ans = max(ans, gcd/i);
        }
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}

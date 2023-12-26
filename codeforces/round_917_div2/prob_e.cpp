#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

const ll MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve() {
    ll n, k; cin >> n >> k;

    if (k&1) {
        cout << "No\n";
        return;
    }

    if (n == 2) {
        if (k == 0)
            cout << "Yes\n0 0\n0 0\n";
        else if (k == 2)
            cout << "Yes\n1 0\n0 1\n";
        else if (k == 4)
            cout << "Yes\n1 1\n1 1\n";
        else cout << "No\n";
        return;
    }

    if (k == n*n-6) {
        int mat[n][n]; memset(mat, 0x11, sizeof(mat));
        mat[n-3][n-3] = 0;
        mat[n-3][n-2] = 0; //  1 1 0
        mat[n-2][n-3] = 0; //  1 0 1 reverse
        mat[n-2][n-1] = 0; //  0 1 1
        mat[n-1][n-2] = 0;
        mat[n-1][n-1] = 0;

        cout << "Yes\n";
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j)
                cout << ((mat[i][j] == 0) ? 0 : 1) << ' ';
            cout << '\n';
        }
        return;
    }

    int mat[n][n]; memset(mat, 0, sizeof(mat));

    if (k%4 == 2 and k>=6) {
        mat[n-3][n-3] = 1;
        mat[n-3][n-2] = 1; //  1 1 0
        mat[n-2][n-3] = 1; //  1 0 1
        mat[n-2][n-1] = 1; //  0 1 1
        mat[n-1][n-2] = 1;
        mat[n-1][n-1] = 1;
        k -= 6;
    }

    int r=0, c=0;
    while (k > 3 and r<n-1) {
        bool free = true;

        // if (r>=n-4 and c>=n-4)
        if (mat[r][c] == 1) free = false;
        if (mat[r+1][c] == 1) free = false;
        if (mat[r][c+1] == 1) free = false;
        if (mat[r+1][c+1] == 1) free = false;

        if (free) {
            mat[r][c] = 1;
            mat[r+1][c] = 1;
            mat[r][c+1] = 1;
            mat[r+1][c+1] = 1;
            k -= 4;
        }

        c +=2;
        if (c==n) {
            c = 0;
            r += 2;
        }
    }

    if (k == 0) {
        cout << "Yes\n";
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j)
                cout << mat[i][j] << ' ';
            cout << '\n';
        }
    } else cout << "No\n";


}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
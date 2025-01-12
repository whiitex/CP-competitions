#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
    int n, m; cin >> n >> m;
    string s; cin >> s;
    vector g(n+1, vi(m+1));
    for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) cin >> g[i][j];


    vi row_sum(n+1), col_sum(m+1);
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            row_sum[i] += g[i][j];
        }
    }
    for (int j=1; j<=m; j++) {
        for (int i=1; i<=n; i++) {
            col_sum[j] += g[i][j];
        }
    }

    vi sumx(n+1), sumy(m+1);
    vector gx(n+1, vi(m+1)), gy(n+1, vi(m+1));
    gx[1][1] = 1; sumx[1] = sumy[1] = 1;

    if (s[0] == 'D') {
        gy[1][1] = -row_sum[1];
        row_sum[1] = 0;
        col_sum[1] += gy[1][1];
    } else {
        gy[1][1] = -col_sum[1];
        col_sum[1] = 0;
        row_sum[1] += gy[1][1];
    }

    int x = 1, y = 1, sum;
    for (int i=0; i<(int)s.size(); ++i) {
        x += s[i] == 'D'; y += s[i] == 'R';

        int inc = 0, off = 0;
        if (i < (int)s.size()-1 and s[i+1] == 'R') {
            inc = 1 - sumy[y];
            off = -col_sum[y];
        } else if (i < (int)s.size()-1 and s[i+1] == 'D') {
            inc = 1 - sumx[x];
            off = -row_sum[x];
        } else {
            assert(x == n); assert(y == m);

            if (sumx[x] == sumy[y]) {
                sum = 0;
            } else {
                sum = (col_sum[y] - row_sum[x]) / (sumx[x] - sumy[y]);
            }

            if (sumx[x] == 0) g[x][y] = sum - row_sum[x];
            else g[x][y] = sum - col_sum[y];

            break;
        }

        gx[x][y] = inc;
        gy[x][y] = off;

        col_sum[y] += off;
        row_sum[x] += off;
        sumx[x] += inc;
        sumy[y] += inc;
    }

    x = 1, y = 1;
    g[1][1] = sum * gx[1][1] + gy[1][1];
    for (int i=0; i<(int)s.size()-1; ++i) {
        x += s[i] == 'D'; y += s[i] == 'R';
        g[x][y] = sum * gx[x][y] + gy[x][y];
    }


    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cout << g[i][j] << " ";
        } cout << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

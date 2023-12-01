#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int par[20][(int)2e5+5];

int rec(int c, int left, int right) {

    int mid = (left + right) >> 1;
    int cl = par[c][mid] - par[c][left];
    int cr = par[c][right] - par[c][mid];

        // base condition: analizing last 1-item partition
    if (left+1 == right) {
        return cr;
    } else {
        // count higher value of char c
        return min(rec(c+1, mid, right) +cl, rec(c+1, left, mid) +cr);
    }
}

void solve() {
    int n;
    string str;
    cin >> n >> str;

    for(int c=0; c<20; ++c)
        for (int i=1; i<=n; ++i)
            par[c][i] = par[c][i-1] + ((str[i-1] -'a') != c);

    cout << rec(0, 0, n) << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

/* DP SOLUTION
        int size = (int) log2(n) + 1;

        // init dp vector
        vector<vector<int>> dp(size);
        for (int i = 0; i < size; ++i) {
            if (i < size - 1) {
                vector<int> useless_pointer((int) pow(2, i + 1), 0);
                dp[i] = useless_pointer;
            } else { // last vec has same size of previous one
                vector<int> useless_pointer((int) pow(2, i), 0);
                dp[i] = useless_pointer;
            }
        }

        // fill dp vector O(d * 2^d)
        for (int i = 0; i < n; ++i) {
            int base = str[i] - 'a';
            if (base == size - 1) --base; // last vec has same size of previous
            if (base <= size - 1) {
                int pts = (int) pow(2, base + 1);
                int pos = i / (n / pts);
                ++dp[str[i] - 'a'][pos];
            }
        }

        // properly sum elements of last two vectors
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0)
                dp[size - 2][i] += dp[size - 1][i + 1];
            else dp[size - 2][i] += dp[size - 1][i - 1];
        }

        // properly sum elements of vectors from '1' to 'size-1'
        for (int i = 0; i < size - 2; ++i) {
            for (int j = 0; j < dp[i].size(); ++j) {
                if (j % 2 == 0) {
                    dp[i + 1][2 * (j + 1)] += dp[i][j];
                    dp[i + 1][2 * (j + 1) + 1] += dp[i][j];
                } else {
                    dp[i + 1][2 * (j - 1)] += dp[i][j];
                    dp[i + 1][2 * (j - 1) + 1] += dp[i][j];
                }
            }
        }

        int mas = 0;
        for (int v: dp[size - 2])
            if (mas < v) mas = v;

        cout << n - mas << '\n';
        */
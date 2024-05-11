#include <bits/stdc++.h>

using namespace std;

//#define int long long
typedef vector<int> vi;

#define pb push_back
#define f first
#define s second

string solve() {
    string s; cin >> s;
    int n = s.length();

    int dp[n][n];
    memset(dp, 0, sizeof(dp));

    for (int l=0; l<n-1; ++l) {
        if (s[l] == s[l+1]) dp[l][l+1] = 0;
        else dp[l][l+1] = 1;
    }

    for (int k=3; k<n; k+=2) {
        for (int i=0; i+k<n; ++i) {
            int r = i+k;

            // sx
            int sx = -2;
            {
                int bob; bool draw = false;
                if (dp[i+2][r] == -1) bob = -1;
                else if (dp[i+1][r-1] == -1) bob = 1;
                else if (dp[i+2][r] == 0 and dp[i+1][r-1] == 0) {
                    if (s[i+1] < s[r]) bob = -1;
                    else bob = 1;
                    draw = true;
                }
                else if (dp[i+2][r] == 0) bob = -1, draw = true;
                else if (dp[i+1][r-1] == 0) bob = 1, draw = true;
                else sx = 1;

                if (sx == -2) {
                    char b = bob == 1 ? s[r] : s[i+1];
                    if (draw) {
                        if (s[i] == b) sx = 0;
                        else if (s[i] < b) sx = 1;
                        else sx = -1;
                    } else sx = -1;
                }
            }

            // dx
            int dx = -2;
            {
                int bob; bool draw = false;
                if (dp[i][r-2] == -1) bob = 1;
                else if (dp[i+1][r-1] == -1) bob = -1;
                else if (dp[i+1][r-1] == 0 and dp[i][r-2] == 0) {
                    if (s[i] == s[r-1]) bob = -1;
                    else bob = 1;
                    draw = true;
                }
                else if (dp[i+1][r-1] == 0) bob = -1, draw = true;
                else if (dp[i][r-2] == 0) bob = 1, draw = true;
                else dx = 1;

                if (dx == -2) {
                    char b = bob == 1 ? s[r-1] : s[i];
                    if (draw) {
                        if (s[r] == b) dx = 0;
                        else if (s[r] < b) dx = 1;
                        else dx = -1;
                    } else dx = -1;
                }
            }

            dp[i][r] = max(sx, dx);
        }
    }

    if (dp[0][n-1] == 0) return "Draw";
    else if (dp[0][n-1] == 1) return "Alice";
    else return "Bob";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) cout << solve() << '\n';
}

#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

#define pb push_back
#define f first
#define s second

const int MOD = 1e9 + 7;

int solve() {
    string s; cin >> s;
    for (char c: s) if (c == 'w' or c == 'm') return 0;

    int MAXN = s.length()+5;
    int dp[MAXN]; dp[0] = 1; dp[1] = 1;
    for (int i=2; i<MAXN; ++i) dp[i] = (dp[i-1] + dp[i-2]) % MOD;

    int ans = 1, n = s.length();
    for (int i=0; i<n; ++i) {

        if (s[i] == 'n') {
            int j = i;
            while (j<n and s[j] == 'n') ++j;
            ans = (ans * dp[j-i]) % MOD;
            i = j-1;
            continue;
        }

        if (s[i] == 'u') {
            int j = i;
            while (j<n and s[j] == 'u') ++j;
            ans = (ans * dp[j-i]) % MOD;
            i = j-1;
            continue;
        }

    }

    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cout << solve() << '\n';
}

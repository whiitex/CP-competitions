#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

#define pb push_back

const int INF = 1e18;

void solve() {
    int n, m; cin >> n >> m;
    unordered_map<string, int> pat;
    int mxp = 0;
    for (int i=0; i<n; ++i) {
        string s; cin >> s; ++pat[s];
        mxp = max(mxp, (int)s.size());
    }

    int cnt = 0;
    while (m--) {
        string s; cin >> s;
        int len = (int)s.size();
        vi dp(len+1); dp[0] = 1;

        for (int i=0; i<len; ++i) if (dp[i]) {
            for (int l=1; l<=mxp and i+l <= len; ++l) {
                string sub = s.substr(i, l);
                if (pat[sub]) dp[i+l] += dp[i];
            }
        }

        cnt += dp[len];
    }

    cout << cnt << '\n';
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();
}

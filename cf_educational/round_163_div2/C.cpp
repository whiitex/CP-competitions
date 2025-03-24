#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef __int128_t lll; typedef long long ll; typedef long double ld;
typedef pair<int,int> pii; typedef pair<ll,ll> pll;
typedef vector<int> vi; typedef vector<ll> vll; typedef vector<pii> vpii; typedef vector<pll> vpll;

#define pb push_back
#define f first
#define s second

const int MAXN = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve() {
    int n; cin >> n;
    char vec[2][n];
    for (int i=0; i<2; ++i) for (int j=0; j<n; ++j) cin >> vec[i][j];

    bool dp[2][n]; memset(dp, false, sizeof(dp));
    dp[0][0] = 1;
    queue<pii> q; q.emplace(0,0);
    int  visited[2][n]; memset(visited, false, sizeof(visited));
    while(!q.empty()) {
        pii p = q.front(); q.pop();
        int o = p.f;
        int i = p.s;
        if (i < n-2 and vec[o][i+1] == '>') {
            dp[o][i+2] = 1;
            if (!visited[o][i+2]) {
                q.emplace(o, i+2);
                visited[o][i+2] = 1;
            }
        }
        if (i < n-1 and vec[o^1][i] == '>') {
            dp[o^1][i+1] = 1;
            if (!visited[o^1][i+1]) {
                q.emplace(o^1, i+1);
                visited[o^1][i+1] = 1;
            }

        } else if (i > 0 and vec[o^1][i] == '<') {
            dp[o^1][i-1] = 1;
            if (!visited[o^1][1-1]) {
                q.emplace(o^1, i-1);
                visited[o^1][i-1] = 1;
            }
        }
    }

    if (dp[1][n-1]) cout << "Yes";
    else cout << "No";
    cout << '\n';

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}

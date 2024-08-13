#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

#define f first
#define s second

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 1e9;

void solve() {
    int n, k, maxposs = 0; cin >> n >> k;
    vpii vec(n); for (pii &i: vec) {
        cin >> i.f >> i.s;
        maxposs += i.f + i.s;
    }

    if (maxposs < k) {
        cout << -1 << '\n'; return;
    }


    vi dp(k + 10, INF); dp[0] = 0;

    for (pii p: vec) {
        int a = min(p.f, p.s);
        int b = max(p.f, p.s);

        for (int i=k+9; i>=0; --i) if (dp[i] != INF) {
            int A = a, B = b;
            int cost = 0;
            for (int j=1; j<=a+b; ++j) {
                if (j + i > k+9) break;
                if (j == a+b-1) continue;

                cost += min(A, B);
                dp[i+j] = min(dp[i+j], cost + dp[i]);
                if (A > B) --A;
                else --B;
            }
        }

    }

    int ans = dp[k];
    for (int i=k; i<k+10; ++i) ans = min(ans, dp[i]);

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

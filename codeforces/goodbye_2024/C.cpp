#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef __int128_t lll; typedef long double ld;
typedef pair<int,int> pii; typedef pair<ld,ld> pld;
typedef vector<int> vi; typedef vector<pii> vpii;

#define pb push_back
#define st first
#define nd second

const int MAXN = 5e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 1e18;

void solve() {
    int n, k; cin >> n >> k;

    int ans = 0;
    int l = 1, r = n, two = 1;
    while (r-l+1 >= k) {
        int m = l+r >> 1;

        int R = n;
        int span = r-l+1;
        if (span & 1) { // odd
            int mn = m;
            int mx = R - m+1;
            ans += (mx+mn) * two / 2;
            r = m-1;
        } else { // even
            r = m;
        }

        two *= 2;
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

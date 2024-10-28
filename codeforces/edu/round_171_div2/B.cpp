#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

const int INF = 1e18;

void solve() {
    int n; cin >> n;
    vi vec(n); for (int &i: vec) cin >> i;

    if (n == 1) {cout << 1 << '\n'; return; }

    int ans1 = 1;
    for (int i=1; i<n; i+=2) {
        ans1 = max(ans1, vec[i] - vec[i-1]);
    }

    if (n % 2 == 0) { cout << ans1 << '\n'; return; }

    int ans = INF;
    for (int k=0; k<n; k+=2) {

        int an = 1;
        for (int i=0; i<n;) {
            if (i+1 < n and i != k and i+1 != k) {
                an = max(an, vec[i+1] - vec[i]);
                i += 2;
            } else if (i+1 >= n) break;
            else ++i;
        }
        ans = min(an, ans);
    }


    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

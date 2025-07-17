#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
    int n, m; cin >> n >> m;
    vi vec(m); for (int &i: vec) cin >> i;

    sort(vec.begin(), vec.end(), greater());
    // reverse(vec.begin(), vec.end());

    vi ans(n+1,1); ans[1] = 0;
    int ok = 1;
    for (int i=2; i<=n and ok; ++i) {
        for (int j=i+i; j<=n and ok; j+=i) {
            if (__gcd(vec[ans[i]], vec[ans[j]]) == vec[ans[__gcd(i,j)]]) {
                ++ans[j];
                if (ans[j] == m) ok = 0;
            }
        }
    }

    for (int i=1; i<=n; ++i) if (ans[i] >= m) ok = 0;

    if (!ok) cout << -1;
    else for (int i=1; i<=n; ++i) cout << vec[ans[i]] << ' ';
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

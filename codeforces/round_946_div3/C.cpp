#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;

void solve() {
    int n; cin >> n;
    vi vec(n); for (int &i: vec) cin >> i;

    map<pii,int> sx, mx, dx;
    map<array<int,3>, int> tot;
    int ans = 0;
    for (int i=0; i<n-2; ++i) {
        int a = vec[i];
        int b = vec[i+1];
        int c = vec[i+2];

        ans += sx[{a,b}];
        ans += mx[{a,c}];
        ans += dx[{b,c}];
        ans -= 3* tot[{a,b,c}];

        sx[{a,b}]++;
        mx[{a,c}]++;
        dx[{b,c}]++;
        tot[{a,b,c}]++;
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}

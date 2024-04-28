#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
    int n; cin >> n;
    vi vec(n); for (int &i: vec) cin >> i;

    std::sort(vec.begin(), vec.end());
    int ans = 0;
    for (int i=0; i<n; ++i) {
        int j=i;
        while (j<n-1 and vec[j] == vec[j+1]) ++j;
        int num = j-i+1; ans += num / 3;
        i = j;
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}

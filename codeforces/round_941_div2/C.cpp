#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

#define pb push_back

void solve() {
    int n; cin >> n;
    vi vec(n); for (int &i: vec) cin >> i;
    vec.pb(0);
    std::sort(vec.begin(), vec.end());

    string alice = "Alice", bob = "Bob"; int win = 1;

    vi ans;
    for (int i=1; i<n+1; ++i) {
        ans.pb(vec[i] - vec[i-1]);
    }

    int i=0;
    while (i<n and ans[i] <= 1) {
        if (ans[i] == 1) win ^= 1;
        ++i;
    }

    if (i<n) win ^= 1;
    cout << (win == 0 ? alice : bob) << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}

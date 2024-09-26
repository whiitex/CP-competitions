#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

#define pb push_back


void solve() {
    int p, k; cin >> p >> k;

    if (p < k) {
        cout << "1\n" << p << '\n'; return;
    }

    vi ans;
    while (p != 0) {
        if (p < 0 and p % -k != 0) p -= k;
        ans.pb(((p % -k) + k) % k);
        p /= -k;
    }

    cout << ans.size() << '\n';
    for (int i: ans) cout << i << ' ';
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; // cin >> t;
    while (t--) solve();
}

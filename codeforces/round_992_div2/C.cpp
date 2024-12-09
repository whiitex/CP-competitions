#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
    int n, k; cin >> n >> k;

    if (n <= 50 and k > (int)pow(2, n-1)) {
        cout << -1 << '\n'; return;
    }

    vi ans(n); int l = 0, r = n-1, rem = n, small = 1;
    while (rem > 50) {
        ans[l] = small; ++small;
        --rem; ++l;
    }

    int tot = (int) pow(2, rem-1);
    for (int i=0; i<rem; ++i) {
        if (tot/2 >= k) {
            ans[l] = small;
            ++l;
        } else {
            ans[r] = small;
            --r;
            k -= tot/2;
        }

        tot /= 2;
        ++small;
    }

    for (int i: ans) cout << i << ' ';
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

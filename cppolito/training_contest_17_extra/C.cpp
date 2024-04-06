#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

#define pb push_back

void solve() {
    int n, x; cin >> n >> x; ++x;
    vi vec(n); for (int& i: vec) cin >> i;

    int ans = -1;
    for (int exp = 30; exp >= 0; --exp) {
        int bit = 1 << exp;

        int count = 0; // count how many numbers
        for (int i=0; i<vec.size(); ++i) {
            if (vec[i] & bit) ++count;
        }

        // fast skip
        if (count & 1 and x & bit) continue;
        if (count & 1) {
            cout << ans << '\n';
            return;
        }

        // even numbers condition
        if (count % 2 == 0) {
            vi newvec;
            for (int j=0; j<vec.size(); ++j) {
                if (vec[j] & bit) {

                    int xr = vec[j];
                    ++j;
                    while (!(vec[j] & bit)) {
                        xr ^= vec[j];
                        ++j;
                    } xr ^= vec[j];

                    newvec.pb(xr);

                } else newvec.pb(vec[j]);
            }

            if (!(x & bit)) vec = newvec;
            else ans = max(ans, int(newvec.size()));

        }

    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}

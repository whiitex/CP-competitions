#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
    int n; cin >> n;
    vi a(n); for (int &i: a) cin >> i;

    int mxt = 0; for (int i: a) mxt = max(mxt, i);
    vi t(mxt + 2);
    for (int i: a) if (i > 0) ++t[i];

    int l = 1, r = n, x = 1, done = 0;
    vi ans(n);
    while (done < n-1) {
        int rev = 0, lft = t[x];
        for (int i=0; i<n; ++i) {
            if (a[i] == -1) rev = 1;

            if (a[i] == x) {
                if (!rev) {
                    if (x & 1) ans[i] = r--;
                    else ans[i] = l++;
                    --lft;
                } else {
                    if (x & 1) {
                        ans[i] = r - lft + 1;
                        --r;
                    } else {
                        ans[i] = l + lft - 1;
                        ++l;
                    }
                    lft -= 2;
                }

                ++done;
            }
        }

        ++x;
    }

    for (int i=0; i<n; ++i) if (a[i] == -1) ans[i] = l;

    for (int i: ans) cout << i << ' '; cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

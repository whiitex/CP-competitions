#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

#define pb push_back

void solve() {
    int n, k; cin >> n >> k;

    if (k == 1) {
        int i=2;
        cout << 25 << '\n';
        for (int j=1; j<25; ++j) {
            cout << i << ' ';
            i *= 2;
        }
        cout << 3 << '\n';
        return;
    }

    vi ans;
    int i = 1;
    int sum = 0;
    int count = 0;
    while ((double)k/(double)i >= 2) {
        sum += i;
        ans.pb(i);
        i *= 2;
        ++count;
    }

    if (k-1-sum > 0) ans.pb(k-1-sum);
    else ans.pb(k+1);
    ++count;

    ans.pb(k+k+1);
    ++count;

    i *= 2;

    if (__builtin_popcount(k+1) == 1) {
        ans.pb(i);
        ++count;
        ans.pb(i+sum+1);
        ++count;
        i*=2;
    } else if (__builtin_popcount(k) != 1) {
        ans.pb(k+1);
        ++count;
    }

    for (; count<25; ++count) {
        ans.pb(i);
        i *= 2;
    }

    cout << 25 << '\n';
    for (int j: ans) cout << j << ' ';
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}

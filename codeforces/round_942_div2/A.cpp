#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
    int n; cin >> n;
    vi a(n); for (int &i: a) cin >> i;
    vi b(n); for (int &i: b) cin >> i;

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    int ans = 0;
    int c = 0;
    for (int i=0; i<n; ++i) {
        if (a[i] > b[c]) {
            ++ans;
            --n;
            --i;
        }++c;
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}

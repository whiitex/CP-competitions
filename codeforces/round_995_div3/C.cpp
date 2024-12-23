#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vi a(m); for (int &i: a) cin >> i;
    vi q(k); for (int &i: q) cin >> i;

    if (k < n-1) {
        for (int i=0; i<m; ++i) cout << 0;
        cout << '\n'; return;
    }

    if (k >= n) {
        for (int i=0; i<m; ++i) cout << 1;
        cout << '\n'; return;
    }

    sort(q.begin(), q.end());
    int lack = 1;
    for (int i: q) {
        if (i == lack) {
            lack++;
        } else break;
    }

    for (int i=0; i<m; ++i) {
        if (a[i] == lack) cout << '1';
        else cout << '0';
    } cout  << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

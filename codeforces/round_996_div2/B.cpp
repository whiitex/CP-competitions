#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

const int INF = 1e18;

void solve() {
    int n; cin >> n;
    vi a(n); for (int &i: a) cin >> i;
    vi b(n); for (int &i: b) cin >> i;

    int cnt = 0, mn = INF, need = 0;
    for (int i=0; i<n; ++i) {
        if (a[i] < b[i]) {
            ++cnt;
            need = b[i] - a[i];
        } else mn = min(mn, a[i] - b[i]);
    }

    if (cnt == 0) cout << "YES\n";
    else {
        if (cnt > 1 or cnt == 1 and n == 1) cout << "NO\n";
        else if (mn >= need) cout << "YES\n";
        else cout << "NO\n";
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;


void solve() {
    int n; cin >> n; n-=2;
    vi a(n); for (int &i: a) cin >> i;

    int ok = 1;
    for (int i=1; i<n-1 and ok; ++i) {
        if (a[i] == 0 and a[i+1] == 1 and a[i-1] == 1) ok = 0;
    }

    cout << (ok ? "YES" : "NO") << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

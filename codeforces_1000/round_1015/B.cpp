#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;

#define pb push_back

void solve() {
    int n; cin >> n;
    vi a(n); for (int &i: a) cin >> i;

    sort(a.begin(), a.end());

    int gcd = a[0];
    vi b;
    for (int i=1; i<n; ++i) {
        if (a[i] % gcd == 0) b.pb(a[i]);
    }

    if (b.empty()) { cout << "No" << '\n'; return; }

    int x = b[0];
    for (int i=1; i<b.size(); ++i) {
        x = __gcd(x, b[i]);
    }

    cout << (gcd == x ? "Yes" : "No") << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

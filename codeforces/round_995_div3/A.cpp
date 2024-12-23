#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
    int n; cin >> n;
    vi a(n); for (int &i: a) cin >> i;
    vi b(n); for (int &i: b) cin >> i;

    int ansa = a[n-1];
    for (int i=0; i<n-1; ++i) if (a[i] > b[i+1]) ansa += a[i] - b[i+1];

    cout << ansa << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
    int n; cin >> n;
    vi a(n); for (int &i: a) cin >> i;

    int allz = 1;
    for (int i: a) if (i != 0) allz = 0;
    if (allz) { cout << 0 << '\n'; return; }

    int i = 0, k = n-1;
    while (i < n and a[i] == 0) ++i;
    int j = i;
    while (j < n and a[j] != 0) ++j; --j;
    while (k >= 0 and a[k] == 0) --k;

    if (k == j)  cout << 1 << '\n';
    else cout << 2 << '\n';
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}
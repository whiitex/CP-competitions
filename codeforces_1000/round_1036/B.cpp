#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;


void solve() {
    int n; cin >> n;
    vi a(n); for (int &i: a) cin >> i;

	if (a[0] > a[1]) cout << a[0] + a[1] << '\n';
	else cout << a[0] * 2 << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

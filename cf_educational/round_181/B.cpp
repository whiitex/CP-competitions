#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
	int a, b, k; cin >> a >> b >> k;

	int gcd = __gcd(a, b);
	if (a/gcd <= k and b/gcd <= k) cout << 1 << '\n';
	else cout << 2 << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
	int l1, l2, l3;
	int b1, b2, b3;
	cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;

	bool ok = false;
	if (l1 == l2 and l2 == l3 and b1 + b2 + b3 == l1) ok = true;
	if (b1 == b2 and b2 == b3 and l1 + l2 + l3 == b1) ok = true;

	if (l2 == l3 and b2 + b3 == b1 and l2 + l1 == b1) ok = true;
	if (b2 == b3 and l2 + l3 == l1 and b2 + b1 == l1) ok = true;

	cout << (ok ? "YES" : "NO") << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

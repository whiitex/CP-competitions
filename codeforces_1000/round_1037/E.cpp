#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
	int n; cin >> n;
	vi p(n); for (int &i: p) cin >> i;
	vi s(n); for (int &i: s) cin >> i;

	bool ok = 1;
	for (int i=1; i<n; ++i) {
		if (p[i-1] % p[i] != 0) ok = 0;
		if (s[i] % s[i-1] != 0) ok = 0;
		if (__gcd(p[i-1], s[i]) != s[0]) ok = 0;
	}

	if (p[n-1] !=  s[0]) ok = 0;

	cout << (ok ? "Yes" : "No") << '\n';
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
}

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int> pii;

const int MOD = 1e9 + 7;

int powerlogn(int b, int exp) {
	int mul = b % MOD, ans = 1;
	while (exp) {
		if (exp & 1) ans = (ans * mul) % MOD;
		mul = (1ll * mul * mul) % MOD;
		exp >>= 1;
	} return ans;
}

void solve() {
	int n, m, k; cin >> n >> m >> k;
	map<pii, int> mp;
	for (int i=0; i<k; ++i) {
		int x, y; cin >> x >> y;
		cin >> mp[{x, y}];
	}

	int ans = -1;
	if (2*n + 2*m - 8 > k) ans = powerlogn(2, n*m - k - 1);
	else {
		int all = 1, p = 0;
		for (int i=2; i<m; ++i) {
			if (!mp.contains({1, i})) all = 0;
			p += mp[{1, i}];
		}
		for (int i=2; i<n; ++i) {
			if (!mp.contains({i, m})) all = 0;
			p += mp[{i, m}];
		}
		for (int i=m-1; i>1; --i) {
			if (!mp.contains({n, i})) all = 0;
			p += mp[{n, i}];
		}
		for (int i=n-1; i>1; --i) {
			if (!mp.contains({i, 1})) all = 0;
			p += mp[{i, 1}];
		}

		if (!all) ans = powerlogn(2, n*m - k - 1);
		else {
			if (p & 1) ans = 0;
			else ans = powerlogn(2, n*m - k);
		}
	}

	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
}

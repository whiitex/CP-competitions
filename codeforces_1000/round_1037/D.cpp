#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
	int n, k; cin >> n >> k;
	vector a(n, vi(3));
	for (int i=0; i<n; ++i) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	}

	sort(a.begin(), a.end());
	for (auto &v: a) {
		if (k >= v[0] and k <= v[1]) {
			k = max(k, v[2]);
		}
	}

	cout << k << '\n';
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
}

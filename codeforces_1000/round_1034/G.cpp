#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
	int n, m, q; cin >> n >> m >> q;
	vi a(n); for (int &i: a) cin >> i;

	map<int, int> mp;
	while (q--) {
		int op; cin >> op;

		if (op == 1) {
			int i, x; cin >> i >> x; --i;
			for (auto &[k, cnt]: mp) {
				int prev = 0;
				if (i and a[i] % k < a[i-1] % k) ++prev;
				if (i < n-1 and a[i+1] % k < a[i] % k) ++prev;

				int now = 0;
				if (i and x % k < a[i-1] % k) ++now;
				if (i < n-1 and a[i+1] % k < x % k) ++now;

				cnt = cnt - prev + now;
			}
			a[i] = x;
		} else { // op == 2
			int k; cin >> k;

			if (__gcd(k, m) == 1) { cout << "YES\n"; continue; }

			k = __gcd(k, m);

			if (!mp.contains(k)) {
				int cnt = 0;
				for (int i=1; i<n; ++i) {
					if (a[i] % k < a[i-1] % k) ++cnt;
				}
				mp[k] = cnt;
			}

			cout << (mp[k] < (m+k-1) / k ? "YES" : "NO") << '\n';
		}
	}

}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
}

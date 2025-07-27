#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;

#define pb push_back

void solve() {
	int n, c; cin >> n >> c;
	vi a(n); for (int &i: a) cin >> i;

	for (int _=0; _<n; ++_) {
		int x = -1;
		for (int i=0; i<a.size(); ++i) {
			if (a[i] <= c) {
				x = max(a[i], x);
			}
		}

		if (x == -1) { cout << a.size() << '\n'; return; }

		vi b; int added = 0;
		for (int i: a) {
			if (i == x and !added) added = 1;
			else b.pb(i * 2);
		}

		swap(a, b);
	}

	cout << 0 << '\n';
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
}

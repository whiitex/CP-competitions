#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;

const int INF = 8e18;

void solve() {
	int n; cin >> n;
	vi a(n); for (int &i: a) cin >> i;

	for (int i=1, mn=INF; i<n; ++i) {
		mn = min(mn, a[i-1]);
		if (a[i] / 2 + 1 > mn) { cout << "NO\n"; return; }
	}

	cout << "YES\n";
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
}

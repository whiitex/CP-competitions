#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
	int n, s; cin >> n >> s;

	int ans = 0;
	for (int i=0; i<n; ++i) {
		int dx, dy, x, y; cin >> dx >> dy >> x >> y;

		if (x == y and dx == dy) { ++ans; continue; }
		if (x + y == s and ((dx == 1 and dy == -1) or (dx == -1 and dy == 1))) {
			++ans;
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

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
	int x; cin >> x;

	int ans = 1;
	vi a(3); a[0] = 1;
	while (a[0] or x and a[1] or x and a[2] or x) {
		a[1] = a[0];
		a[2] = min(x, a[1] * 2 + 1);
		ans += 2;
		reverse(a.begin(), a.end());
	}

	cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
    int n, x; cin >> n >> x;
	string s; cin >> s;

	--x;
	int l = x-1, r = x+1, ans = 0;
	while (1) {
		if (l == x) --l;
		if (r == x) ++r;
		while (l >= 0 and s[l] == '.') --l;
		while (r < n and s[r] == '.') ++r;

		++ans;
		if (l == -1 and r == n) break;
		if (x == 0 or x == n-1) break;

		if (l == -1) l = x-1;
		else if (r == n) r = x+1;
		else {
			int cntl  = l + 2, cntr = n-r+1;
			if (cntl < cntr) l = x-1;
			else r = x+1;
		}
		s[l] = '#'; s[r] = '#';

		int cntl  = l + 2, cntr = n-r+1;
		if (cntl < cntr) x = l;
		else x = r;
	}

	cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

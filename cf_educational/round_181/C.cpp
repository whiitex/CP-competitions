#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;


void solve() {
	int l, r; cin >> l >> r;

	vi primes = {2, 3, 5, 7};
	int bad = 0;

	int m = 4;
	for (int mask=1; mask < (1 << m); ++mask) {
		int lcm = 1, bits = 0;
		for (int i=0; i<m; ++i) {
			if (mask & (1 << i)) {
				lcm = lcm * primes[i];
				++bits;
			}
		}

		int cnt = r / lcm - (l - 1) / lcm;
		if (bits & 1) bad += cnt;
		else bad -= cnt;
	}

	cout << (r - l + 1) - bad << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

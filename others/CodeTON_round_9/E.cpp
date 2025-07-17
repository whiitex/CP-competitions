#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 998244353;

void solve() {
    int n; cin >> n;

	int ans = 0, one = 0, zero, add = 0;
	for (int i=3; i<=n; ++i) {

		zero = (one+3) * one / 2 % MOD;
		zero = (zero + add) % MOD;

		ans = (ans + zero) % MOD;
		add = (add + zero * i) % MOD;
		++one;
	}

	cout << (ans + n - 1) % MOD << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

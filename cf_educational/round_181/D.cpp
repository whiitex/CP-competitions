#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;

#define pb push_back

const int MOD = 998244353;


int powerlogn(int b, int exp) {
	int mul = b % MOD, ans = 1;
	while (exp) {
		if (exp & 1) ans = (ans * mul) % MOD;
		mul = (1ll * mul * mul) % MOD;
		exp >>= 1;
	} return ans;
}

int inv(int v) {
	return powerlogn(v, MOD-2) % MOD;
}


void solve() {
    int n, m; cin >> n >> m;

	int PNO = 1;
	vector start(m+1, vector<array<int,3>>());
	for (int i=0; i<n; ++i) {
		int l, r, p, q;
		cin >> l >> r >> p >> q;
		start[l].pb({r, p, q});
		PNO = (PNO * (q-p)) % MOD;
		PNO = (PNO * inv(q)) % MOD;
	}

	vi dp(m+1, 0); dp[0] = 1;
	for (int i=1; i<=m; ++i) {

		for (auto s: start[i]) {
			int pok = (s[1] * inv(s[2] - s[1])) % MOD;
			dp[s[0]] = (dp[s[0]] + dp[i-1] * pok) % MOD;
		}
	}

	cout << (dp[m] * PNO) % MOD << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();
}

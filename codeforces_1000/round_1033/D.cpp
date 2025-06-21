#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;

const int MXN = 5e5 + 5;
const int MOD = 1e9 + 7;

vector<int> fact(MXN, 1);
vector<int> invfact(MXN, 1);

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

int binomial(int a, int b) {
	int ans = 1;
	for (int i=0; i<b; ++i) {
		ans = (ans * (a-i)) % MOD;
	}
	return (ans * invfact[b]) % MOD;
}

void precompute() {
	for (int i=2; i<MXN; ++i) {
		fact[i] = (fact[i-1] * i) % MOD;
		invfact[i] = inv(fact[i]);
	}
}

void solve() {
	int a, b, k; cin >> a >> b >> k;

	if (a == 1 and b == 1) { cout << "1 1\n"; return; }
	if (k == 1) { cout << a << ' ' << b << '\n'; return; }

	int n = ((a-1) * k + 1) % MOD;
	int m = (binomial(n, a) * k) % MOD;
	m = (m * (b-1)) % MOD;

	cout << n << ' ' << (m+1)%MOD << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	precompute();

    int t = 1; cin >> t;
    while (t--) solve();
}

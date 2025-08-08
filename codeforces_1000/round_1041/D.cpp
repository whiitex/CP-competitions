#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;

#define pb push_back

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
	int ans = (fact[a] * invfact[b]) % MOD;
	return (ans * invfact[a-b]) % MOD;
}

void precompute() {
	for (int i=2; i<MXN; ++i) {
		fact[i] = (fact[i-1] * i) % MOD;
		invfact[i] = inv(fact[i]);
	}
}

void solve() {
	int n, m; cin >> n >> m;
	vector adj(n+1, vi());
	for (int i=0; i<m; ++i) {
		int u, v; cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}

	if (m != n-1) { cout << "0\n"; return; }
	if (n == 2) { cout << "2\n"; return; }

	vi cntadjone(n+1);
	vector cntadjmore(n+1, vi());
	for (int u=1; u<=n; ++u) {
		for (int v: adj[u]) {
			if (adj[v].size() == 1) {
				cntadjone[u]++;
			} else cntadjmore[u].pb(v);
		}
	}

	int start = -1, end = -1;
	for (int u=1; u<=n; ++u) {
		if (cntadjmore[u].size() == 1 and adj[u].size() > 1) {
			if (start == -1) start = u;
			else if (end == -1) end = u;
			else { cout << "0\n"; return; }
		}
	}
	if (end == -1) end = start;

	if (start == -1) {
		for (int i=1; i<=n; ++i) if (adj[i].size() == n-1) {
			cout << fact[n-1] * 2 % MOD << "\n";
			return;
		}
		cout << "0\n"; return;
	}

	int ans = 1, x = start;
	vi done(n+1);
	while (1) {
		ans = ans * fact[cntadjone[x]] % MOD;
		done[x] = 1;

		if (x == end) break;
		if (done[cntadjmore[x][0]]) x = cntadjmore[x][1];
		else x = cntadjmore[x][0];
	}

	if (start != end) ans = ans * 2 % MOD;
	cout << ans * 2 % MOD << "\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	precompute();

    int t = 1; cin >> t;
    while (t--) solve();
}

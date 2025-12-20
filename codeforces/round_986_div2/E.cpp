#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef __int128_t lll; typedef long double ld;
typedef pair<int,int> pii; typedef pair<ld,ld> pld;
typedef vector<int> vi; typedef vector<pii> vpii;

#define pb push_back
#define st first
#define nd second

const int MAXN = 5e5 + 5;
const int MOD = 998244353;
const int INF = 1e18;

struct Z {
	int val;
	explicit operator int() const { return val; }
	Z() { val = 0; }
	template<class U> Z(const U& v) {
		val = (-MOD <= v && v <= MOD) ? v : v % MOD;
		if (val < 0) val += MOD;
	}
	friend istream& operator<<(istream& is, Z& a) { is >> a.val; }
	friend ostream& operator<<(ostream& os, const Z& a) { return os << a.val; }
	friend bool operator==(const Z& a, const Z& b) { return a.val == b.val; }
	friend bool operator!=(const Z& a, const Z& b) { return !(a == b); }

	Z operator-() const { return Z(-val); }
	Z& operator+=(const Z& m) { if ((val += m.val) >= MOD) val -= MOD; return *this; }
	Z& operator-=(const Z& m) { if ((val -= m.val) < 0) val += MOD; return *this; }
	Z& operator*=(const Z& m) { val = (int)val*m.val%MOD; return *this; }
	friend Z exp(Z a, int p) {
		Z ans = 1; for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
	}
	friend Z inv(const Z& a) { return exp(a, MOD-2); }
	Z& operator/=(const Z& m) { return (*this) *= inv(m); }

	friend Z operator+(Z a, const Z& b) { return a += b; }
	friend Z operator-(Z a, const Z& b) { return a -= b; }
	friend Z operator*(Z a, const Z& b) { return a *= b; }
	friend Z operator/(Z a, const Z& b) { return a /= b; }
};

void solve() {
	int n; cin >> n;
	vector adj(n+1, vi());
	for (int i=1; i<n; ++i) {
		int u, v; cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}

	vi dep(n+1, INF), par(n+1), fromtop(n+1, INF);
	auto dfs = [&](auto f, int u, int tp=0) -> int {
		fromtop[u] = tp;
		int d = INF;
		for (int v: adj[u]) if (par[u] != v) {
			par[v] = u;
			d = min(d, f(f, v, tp+1) + 1);
		}

		return dep[u] = d == INF ? 0 : d;
	}; dfs(dfs, 1);


	vector<Z> ans(n + 1); ans[1] = Z(1);
	auto dfs2 = [&](auto f, int u) -> void {
		if (u > 1) ans[u] = ans[par[u]] * Z(dep[u]) / Z(dep[u] + 1);
		for (int v: adj[u]) if (par[u] != v) f(f, v);
	}; dfs2(dfs2, 1);


	for (int i=1; i<=n; ++i) cout << ans[i].val << " \n"[i == n];
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

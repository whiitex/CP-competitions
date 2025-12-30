// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

#define pb push_back
#define st first
#define nd second

constexpr int MXN = 5e5 + 5;
constexpr int MOD = 998244353;
constexpr int INF = 8e18;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int uniform_distr(int a, int b) {
	return uniform_int_distribution<int>(a, b)(rng);
}

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

struct Comb {
	int n;
	vector<Z> _fac, _invfac;

	Comb() : n{0}, _fac{1}, _invfac{1}, _inv{0} {}
	Comb(int n) : Comb() { init(n); }

	void init(int m) {
		if (m <= n) return;
		_fac.resize(m + 1);
		_invfac.resize(m + 1);
		_inv.resize(m + 1);

		for (int i = n + 1; i <= m; i++) {
			_fac[i] = _fac[i - 1] * i;
		}
		_invfac[m] = 1/_fac[m];
		for (int i = m; i > n; i--) {
			_invfac[i - 1] = _invfac[i] * i;
			_inv[i] = _invfac[i] * _fac[i - 1];
		}
		n = m;
	}

	Z fac(int m) {
		if (m > n) init(2 * m);
		return _fac[m];
	}
	Z invfac(int m) {
		if (m > n) init(2 * m);
		return _invfac[m];
	}
	Z binom(int n, int m) {
		if (n < m || m < 0) return 0;
		return fac(n) * invfac(m) * invfac(n - m);
	}

private:
	vector<Z> _inv;
	Z inv(int m) {
		if (m > n) init(2 * m);
		return _inv[m];
	}
} C;


void solve() {
    int n; cin >> n;
	int bonus; cin >> bonus;
    vi a(n); for (int &i: a) cin >> i;

	if (n == 1) { cout << "1\n"; return; }

	sort(a.begin(), a.end());

	int need = 0;
	for (int i=0; i<n; ++i) {
		if (a[i] == a.back()) continue;
		need += a.back() - a[i] - 1;
		a[i] = a.back() - 1;
	}

	if (need > bonus) { cout << "0\n"; return; }
	bonus -= need;

	int bg = 0, bg1 = 0;
	for (int i: a) bg1 += i == a.back() - 1;

	Z ans = 1;

	if (bonus <= bg1) {
		ans *= C.binom(bg1, bonus);
		ans *= C.fac(n - bg1 + bonus);
		ans *= C.fac(bg1 - bonus);
	} else {
		bonus %= n;
		ans *= C.binom(n, bonus);
		ans *= C.fac(bonus);
		ans *= C.fac(n - bonus);
	}

	cout << ans << '\n';
}

void solve2() { }

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s = "f"; // cin >> s;
	int t = 1; cin >> t;
	while (t--) s[0] == 'f' ? solve() : solve2();
}
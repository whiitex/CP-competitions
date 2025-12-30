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

constexpr int MXN = 6e5 + 5;
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
		if (m > n) init(2 *  m);
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
} C(MXN);

template<typename T> struct SegmentTree {
    T neutral = 0; // CHANGE (neutral element)
    int n;
    vector<T> tree;

    SegmentTree (vector<T> &vec) : n((int)vec.size()), tree(2*n) { // n is a power of 2
        for (int i=0; i<n; ++i) tree[n+i] = vec[i];
        for (int i=n-1; i>=1; --i) tree[i] = merge(tree[i*2], tree[i*2+1]);
    }

	T query(int l, int r) { return query(1, 0, n-1, l, r); } // l/r is 0-indexed
	int getminpos(int l, int r) { return getminpos(1, 0, n-1, l, r); } // l/r is 0-indexed
	void update(int pos, T v) { update(1, 0, n-1, pos, v); } // pos is 0-indexed

	T query(int pos, int node_l, int node_r, int query_l, int query_r) { // query 0-indexed

    	if (node_r <= query_r && node_l >= query_l) return tree[pos];
    	if (node_l > query_r || node_r < query_l) return neutral;

    	int max_l = (node_l + node_r) >> 1;
    	T q1 = query(pos<<1, node_l, max_l, query_l, query_r);
    	T q2 = query((pos<<1)+1, max_l+1, node_r, query_l, query_r);
    	return merge(q1, q2); // operation
    }

    void update(int pos, int node_l, int node_r, int change_pos, T v) {
        if (change_pos == node_l && change_pos == node_r) {
            tree[pos] += v; return;
        }

        if (change_pos > node_r || change_pos < node_l) return;

        int max_l = (node_l + node_r) >> 1;
        update(pos<<1, node_l, max_l, change_pos, v);
        update((pos<<1)+1, max_l+1, node_r, change_pos, v);
        tree[pos] = merge(tree[pos<<1], tree[(pos<<1)+1]); // operation
    }

    T merge(T a, T b) { // COMPLETE (function)
        return a + b;
    }
};

vector<Z> two(MXN, Z(1));
Z precalc[MXN][61];

void solve() {
	int n, q; cin >> n >> q;

	vi a(64); for (int i=0; i<n; ++i) {
		int x; cin >> x; ++a[x];
	}

	while (q--) {
		int op, x; cin >> op >> x;

		if (op == 1) ++a[x];
		if (op == 2) --a[x];
		if (op == 3) {

			SegmentTree sgt(a);

			Z ans = Z(0), mul2 = Z(1);
			int mx = 61, taken = 0, impossible = 0;
			vi fleet(64);

			for (int bit=61; bit>=0; --bit) if ((x >> bit) & 1) {

				int need = bit + taken;

				if (need < mx) {

					int tot = sgt.query(need+1, mx-1);

					Z mul1 = two[a[mx]] - precalc[a[mx]][fleet[mx]];

					int count = sgt.query(0, need);

					ans += (two[tot] - 1) * C.binom(a[mx], fleet[mx]) * mul2 * two[count];
					ans += two[tot] * mul1 * mul2 * two[count];
				}

				if (sgt.query(need, need) <= 0) { impossible = 1; break; }


				// update
				sgt.update(need, -1);
				++fleet[need];
				if (need < mx) mul2 *= C.binom(a[mx], fleet[mx]);
				mx = need;
				++taken;
			}

			Z mul = two[a[mx]] - precalc[a[mx]][fleet[mx]-1];;
			for (int i=61; i>mx; --i) mul *= C.binom(a[i], fleet[i]);

			if (!impossible) ans += (mx > 0 ? two[sgt.query(0, mx-1)] : Z(1)) * mul;

			cout << ans << '\n';
		}
	}

}

void solve2() { }

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int i=1; i<MXN; i++) two[i] = two[i-1] * Z(2);
	for (int n=0; n<MXN; ++n) {
		Z sm = Z(0);
		for (int k=0; k<min(60ll, n+1); ++k) {
			sm += C.binom(n, k);
			precalc[n][k] = sm;
		}
	}

	string s = "f"; // cin >> s;
	int t = 1; //cin >> t;
	while (t--) s[0] == 'f' ? solve() : solve2();
}
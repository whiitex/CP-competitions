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
constexpr int MOD = 1e9 + 7;
constexpr int INF = 8e18;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int uniform_distr(int a, int b) {
	return uniform_int_distribution<int>(a, b)(rng);
}


void solve() {
	int n, q; cin >> n >> q;
	vpii rng(q); for (auto &[l,r]: rng) cin >> l >> r;

	vi mxr(n+10, -1);
	for (auto [l, r]: rng) {
		mxr[l] = max(mxr[l], r);
	}
	vpii a;
	for (int i=1, mx=0; i<=n; ++i) {
		if (mxr[i] > mx) {
			mx = mxr[i];
			a.pb({i, mx});
		}
	}

	map<pii,int> memo;
	auto ask = [&] (int l, int r) -> int {
		if (!memo.contains({l, r})) {
			cout << "? " << l << " " << r;
			cout << endl; cout.flush();
			int res; cin >> res;
			memo[{l, r}] = res;
		}
		return memo[{l, r}];
	};

	while (a.size() > 1) {
		vpii b; for (int i=0; i<a.size()/2; ++i) b.pb(a[i]);
		vpii c; for (int i=a.size()/2; i<a.size(); ++i) c.pb(a[i]);

		int mexb = ask(b[0].st, b.back().nd);
		int mexc = ask(c[0].st, c.back().nd);

		mexb >= mexc ? swap(b, a) : swap(c, a);
	}

	int ans = ask(a[0].st, a[0].nd);

	cout << "! " << ans << endl; cout.flush();
}

void solve2() { }

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s = "f"; // cin >> s;
	int t = 1; cin >> t;
	while (t--) s[0] == 'f' ? solve() : solve2();
}
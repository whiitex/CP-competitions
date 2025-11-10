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
    int n; cin >> n;
    vi a(n); for (int &i: a) cin >> i;
	string x; cin >> x;

	int no = 0;
	if (x[0] == '1' or x[n-1] == '1') no = 1;
	for (int i=0; i<n; ++i) if (x[i] == '1') {
		if (a[i] == 1 or a[i] == n) no = 1;
	}
	if (no) { cout << -1 << '\n'; return; }

	int allzero = 1;
	for (char c: x) if (c == '1') allzero = 0;
	if (allzero) { cout << 0 << '\n'; return; }


	vpii ans;
	int one, en;
	for (int i=0; i<n; ++i) {
		if (a[i] == 1) one = i;
		if (a[i] == n) en = i;
	}

	string cover(n, '0');
	auto doit = [&](int l, int r) {
		if (l > r) swap(l, r);
		ans.pb({l, r});
		int mn = min(a[l], a[r]);
		int mx = max(a[l], a[r]);
		for (int i=l+1; i<r; ++i) {
			if (a[i] > mn and a[i] < mx) cover[i] = '1';
		}
	};

	doit(one, en);

	int first1 = 0, last1 = n-1;
	while (x[first1] == '0') ++first1;
	while (x[last1] == '0') --last1;

	int mnlx = INF, mnlxidx=-1, mxlx = -1, mxlxidx=-1;
	for (int i=0; i<first1; ++i) {
		if (a[i] < mnlx) {
			mnlx = a[i];
			mnlxidx = i;
		}
		if (a[i] > mxlx) {
			mxlx = a[i];
			mxlxidx = i;
		}
	}
	doit(mnlxidx, en);
	doit(mxlxidx, one);

	int mnrx = INF, mnrxidx=-1, mxrx = -1, mxrxidx=-1;
	for (int i=last1+1; i<n; ++i) {
		if (a[i] < mnrx) {
			mnrx = a[i];
			mnrxidx = i;
		}
		if (a[i] > mxrx) {
			mxrx = a[i];
			mxrxidx = i;
		}
	}
	doit(mnrxidx, en);
	doit(mxrxidx, one);


	int ok = 1;
	for (int i=0; i<n; ++i) {
		if (x[i] == '1' and cover[i] == '0') ok = 0;
	}

	if (ok) {
		cout << ans.size() << '\n';
		for (auto [l, r]: ans) cout << l+1 << ' ' << r+1 << '\n';
	} else cout << -1 << '\n';
}

void solve2() { }

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s = "f"; // cin >> s;
	int t = 1; cin >> t;
	while (t--) s[0] == 'f' ? solve() : solve2();
}
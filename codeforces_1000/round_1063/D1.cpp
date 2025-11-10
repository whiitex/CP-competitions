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

	int cntquery = 0;

	map<pii,int> memo;
	auto ask = [&] (int l, int r) -> int {
		if (!memo.contains({l, r})) {
			cout << "? " << l << " " << r;
			cout << endl; cout.flush();
			int res; cin >> res;
			memo[{l, r}] = res;
		}
		++cntquery;
		if (cntquery > max(300ll, (n+1)/2+2)) exit(1);
		return memo[{l, r}];
	};

	auto getminR = [&] (int mex) -> int {
		int lo = 1, hi = n;
		while (lo < hi) {
			int mid = lo + hi >> 1;
			ask(1, mid) >= mex ? hi = mid : lo = mid + 1;
		} return lo;
	};

	auto getmaxL = [&] (int mex) -> int {
		int lo = 1, hi = n;
		while (lo < hi) {
			int mid = lo + hi + 1 >> 1;
			ask(mid, n) >= mex ? lo = mid : hi = mid - 1;
		} return lo;
	};

	int lo = 0, hi = n;
	while (lo < hi) {
		int mid = lo + hi + 1 >> 1;

		int L = getmaxL(mid);
		int R = getminR(mid);

		bool ok = 0;
		for (auto [l,r]: rng) {
			if (l <= L and r >= R) {
				ok = 1; break;
			}
		}

		ok ? lo = mid : hi = mid - 1;
	}

	cout << "! " << lo << endl; cout.flush();
}

void solve2() { }

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s = "f"; // cin >> s;
	int t = 1; cin >> t;
	while (t--) s[0] == 'f' ? solve() : solve2();
}
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

map<pii,int> memo;
int ask(int l, int r) {
	if (!memo.contains({l,r})) {
		cout << "? " << l << " " << r << endl;
		int res; cin >> res; memo[{l,r}] = res;
	} return memo[{l,r}];
}

void solve() {
    int n; cin >> n;
	memo.clear();

	int l = 1, r = n;
	while (r - l + 1 > 1) {

		int tot = ask(l, r);

		int lo = l, hi = r;
		while (lo < hi) {
			int mid = lo + hi >> 1;

			int lx = ask(l, mid);
			lx >= tot / 2 ? hi = mid : lo = mid + 1;
		}

		int ln1 = lo - l + 1;
		int ln2 = r - lo;

		if (ln1 < ln2) r = lo;
		else l = lo + 1;
	}

	int ans = ask(l, r);
	cout << "! " << ans << endl;
}

void solve2() { }

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s = "f"; // cin >> s;
	int t = 1; cin >> t;
	while (t--) s[0] == 'f' ? solve() : solve2();
}
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
	int n, m, k; cin >> n >> m >> k;
	multiset<int> box;
	for (int i=0; i<m; ++i) {
		int x; cin >> x; box.insert(x);
	}
	vi x(n), y(n), z(n);
	for (int i=0; i<n; ++i) cin >> x[i] >> y[i] >> z[i];

	for (int i=0; i<n; ++i) k -= y[i], z[i] -= y[i];

	set<int> done;

	vpii o(n); for (int i=0; i<n; ++i) o[i] = {z[i], x[i]};
	sort(o.begin(), o.end());

	int ans = 0;

	for (int i=n-1; i>=0; --i) {
		auto [coins, needbox] = o[i];
		if (box.empty()) continue;
		auto it = box.lower_bound(needbox);
		if (it != box.end()) {
			done.insert(i);
			++ans;
			box.erase(it);
		}
	}

	for (int i=0; i<n; ++i) if (!done.contains(i)) {
		if (o[i].st <= k) k -= o[i].st, ++ans;
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
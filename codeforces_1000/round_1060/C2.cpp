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

vector<vi> divs(MXN);

void solve() {
	int n; cin >> n;
	vi a(n); for (int &i: a) cin >> i;
	vi b(n); for (int &i: b) cin >> i;

	map<int,int> cnt;
	for (int x: a) for (int d: divs[x]) {
		if (cnt[d]) { cout << 0 << '\n'; return; }
		++cnt[d];
	}

	vi o(n); iota(o.begin(), o.end(), 0);
	sort(o.begin(), o.end(), [&](int i, int j) {
		return b[i] < b[j];
	});

	int ans = b[o[0]] + b[o[1]];
	for (int i=0; i<n; ++i) {
		for (int d: divs[a[i]]) --cnt[d];

		for (int d: divs[a[i]+1]) {
			if (cnt[d]) ans = min(ans, b[i]);
		}

		for (int d: divs[a[i]]) ++cnt[d];
	}

	unordered_set<int> check;
	for (int i=0; i<n; ++i) if (i != o[0]) {
		for (int d: divs[a[i]]) check.insert(d);
	}

	for (int ck: check) {
		int t = ck - (a[o[0]] % ck);
		if (t == ck) t = 0;

		ans = min(ans, b[o[0]] * t);
	}

	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int i=2; i<MXN; ++i) {
		for (int j=i; j<MXN; j+=i) {
			divs[j].pb(i);
		}
	}

	int t = 1; cin >> t;
	while (t--) solve();
}

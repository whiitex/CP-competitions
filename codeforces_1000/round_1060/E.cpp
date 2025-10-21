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
	int n, k; cin >> n >> k;
	vi a(n+1); for (int i=1; i<=n; ++i) cin >> a[i];

	sort(a.begin()+1, a.end());

	vi p(a); for (int i=2; i<=n; ++i) p[i] += p[i-1];


	auto count = [&](int x, int i) -> int {
		int cntlp = min(i-1, k * (x-1));
		int cntl = min(i-1, k * x);
		int res = (cntl - cntlp) * a[i] - (p[cntl] - p[cntlp]);
		res += a[i] - a[i+x];

		return res;
	};

	int ans = p[n];
	for (int i=2; i<n; ++i) {

		int l = 1, r = min(i-1, n - i);
		while (l < r) {
			int m = l + r + 1 >> 1;
			count(m, i) > 0 ? l = m : r = m - 1;
		}

		int cntl = min(i-1, k * l);
		int res = a[i] * (l + cntl + 1);
		res += p[n] - p[i + l];
		res += p[i-1] - p[cntl];

		ans = max(ans, res);
	}

	cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

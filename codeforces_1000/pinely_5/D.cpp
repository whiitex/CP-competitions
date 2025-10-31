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
    int N; cin >> N;
    vi A(N); for (int &i: A) cin >> i;

	vi a(1), c(1);
	for (int i=0; i<N; ++i) {
		int j = i;
		while (j + 1 < N and A[j+1] == A[i]) ++j;
		a.pb(A[i]);
		c.pb(j - i + 1);
		i = j;
	}
	int n = (int)a.size();

	vector pos(N+1, vi(1, 0));
	for (int i=1; i<n; ++i) pos[a[i]].pb(i);

	vpii dp; dp.pb({0,0}); // pos, cost
	for (int v=N; v>0; --v) {

		vpii ndp;

		int mncost = dp[0].nd, inccost = 0;
		int remcost = 0; for (int i: pos[v]) remcost += c[i];

		vpii position;
		for (auto [p, cost]: dp) position.pb({p, v+1});
		for (int i: pos[v]) if (i) position.pb({i, v});
		sort(position.begin(), position.end());

		for (auto [i, V]: position) {

			if (V == v) {
				remcost -= c[i];
				ndp.pb({i, remcost + mncost});
				inccost += c[i];
			} else {
				mncost = min(mncost, inccost + lower_bound(dp.begin(), dp.end(), pii{i,-INF})->nd);
			}
		}

		int mn = INF;
		for (auto [p, cost]: dp) mn = min(mn, cost);
		ndp.pb({0, mn + inccost});

		swap(ndp, dp);
		sort(dp.begin(), dp.end());
	}

	int ans = INF;
	for (auto [p, cost]: dp) {
		ans = min(ans, cost);
	}

	cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}
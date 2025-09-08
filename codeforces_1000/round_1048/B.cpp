// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef __int128_t lll; typedef long double ld;
typedef pair<int,int> pii; typedef pair<ld,ld> pld;
typedef vector<int> vi; typedef vector<pii> vpii;

#define pb push_back
#define st first
#define nd second

const int MXN = 5e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 8e18;

void solve() {
	int n, q; cin >> n >> q;
	vi a(n); for (int &i: a) cin >> i;

	// find first bigger left
	vi biglx(n);
	stack<pii> s;
	for (int i=0; i<n; ++i) {
		while (!s.empty() and s.top().st < a[i]) s.pop();
		biglx[i] = s.empty() ? -1 : s.top().nd;
		s.push({a[i], i});
	}

	// find first smaller right
	vi smallrx(n);
	while (!s.empty()) s.pop();
	for (int i=n-1; i>=0; --i) {
		while (!s.empty() and s.top().st > a[i]) s.pop();
		smallrx[i] = s.empty() ? n : s.top().nd;
		s.push({a[i], i});
	}

	vi dp(n+1, n);
	for (int i=n-1; i>=0; --i) {
		if (biglx[i] != -1) {
			dp[biglx[i]] = min(dp[biglx[i]], smallrx[i]);
		}
		dp[i] = min(dp[i], dp[i+1]);
	}

	while (q--) {
		int l, r; cin >> l >> r; --l, --r;
		cout << (dp[l] > r ? "YES\n" : "NO\n");
	}
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

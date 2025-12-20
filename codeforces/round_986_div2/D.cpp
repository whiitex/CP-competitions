#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef __int128_t lll; typedef long double ld;
typedef pair<int,int> pii; typedef pair<ld,ld> pld;
typedef vector<int> vi; typedef vector<pii> vpii;

#define pb push_back
#define st first
#define nd second

const int MAXN = 5e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 1e18;

void solve() {
	int n; cin >> n;
	vector a(3, vi(n+1));
	for (int i=0; i<3; ++i) {
		for (int j=1; j<=n; ++j) cin >> a[i][j];
	}

	string s = "qkj";
	vi mn{n, n, n};
	vector ans(n+1, pair<char, int>({'x', -1}));
	for (int i=n-1; i>=1; --i) {
		for (int p=0; p<3; ++p) {
			if (a[p][i] > a[p][mn[p]]) {
				ans[i] = {s[p], mn[p]};
				for (int pp=0; pp<3; ++pp) {
					if (a[pp][i] < a[pp][mn[pp]]) mn[pp] = i;
				}
				break;
			}
		}
	}

	if (ans[1].st != 'x') {
		cout << "YES\n";

		vector<pair<char, int>> Ans;
		int x = 1;
		while (x != n) {
			Ans.pb(ans[x]);
			x = ans[x].nd;
		}

		cout << Ans.size() << "\n";
		for (auto [c, y]: Ans) cout << c << ' ' << y << '\n';
	} else cout << "NO\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

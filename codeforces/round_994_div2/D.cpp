#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

const int INF = 1e18;

int dp[205][205][205];

void solve() {
	int n, m, k; cin >> n >> m >> k;
	vector grid(n+1, vi(m));
	for (int i=1; i<=n; i++) {
		for (int j=0; j<m; j++) {
			cin >> grid[i][j];
			for (int q=0; q<m; ++q) dp[i][j][q] = INF;
		}
	}

	vector best(n+1, vi(m, INF)); best[0][0] = 0;
	for (int i=1; i<=n; ++i) {
		for (int j=0; j<m; ++j) {

			// comes from best above
			for (int sh=0; sh<m; ++sh) {
				int posj = (j+sh) % m;
				dp[i][j][sh] = min(dp[i][j][sh], best[i-1][j] + sh*k + grid[i][posj]);

				// comes from left
				if (j < m-1) dp[i][j+1][sh] = min(dp[i][j+1][sh], dp[i][j][sh] + grid[i][(posj+1)%m]);
			}

			// update best
			for (int sh=0; sh<m; ++sh) {
				best[i][j] = min(best[i][j], dp[i][j][sh]);
			}
		}
	}

	cout << best[n][m-1] << '\n';
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
}

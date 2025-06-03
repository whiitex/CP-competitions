#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
	int n, m; cin >> n >> m;

	set<int> rooms;
	for (int i=0; i<m; ++i) {
		int x; cin >> x; rooms.insert(x);
	}

	vector ans(n+3, vi(6));
	for (int i=0; i<n; i+=2) {
		int big = *rooms.rbegin();
		int small = *rooms.begin();
		rooms.erase(big);
		rooms.erase(small);

		ans[i][0] = ans[i][2] = ans[i][4] = big;
		ans[i][1] = ans[i][3] = ans[i][5] = small;
		ans[i+1][0] = ans[i+1][2] = ans[i+1][4] = small;
		ans[i+1][1] = ans[i+1][3] = ans[i+1][5] = big;
	}

	for (int i=0; i<n; ++i) {
		for (int j=0; j<6; ++j) {
			cout << ans[i][j] << " ";
		} cout << '\n';
	}

}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

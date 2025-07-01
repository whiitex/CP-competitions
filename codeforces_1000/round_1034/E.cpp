#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
	int n; cin >> n;
	vi a(n); for (int &i: a) cin >> i;

	vi f(n+1); for (int i: a) ++f[i];

	vi t(n+10);
	for (int x=0; x<=n; ++x) {
		++t[f[x]];
		--t[n-x+1];
		if (f[x] == 0) break;
	}

	vi ans(n+1);
	for (int i=0, cnt=0; i<n; ++i) {
		cnt += t[i];
		ans[i] = cnt;
	} ans[n] = 1;

	for (int i: ans) cout << i << ' '; cout << '\n';
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
}

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

#define st first
#define nd second

const int INF = 8e18;

void solve() {
	int n, k; cin >> n >> k;
	vi a(n); for (int &i: a) cin >> i;

	auto check = [&] (int x) -> vi {
		vi b(n);
		for (int i=0; i<n; ++i) {
			b[i] = a[i] >= x ? 1 : -1;
		}
		for (int i=1; i<n; ++i) b[i] += b[i-1];

		vpii s(n+1, {-INF, -INF});
		for (int i=n-1; i>=0; --i) {
			if (b[i] > s[i+1].st) {
				s[i] = {b[i], i};
			} else {
				s[i] = s[i+1];
			}
		}

		vi ans = {0, 0, 0};
		for (int i=0, cnt = 0; i<=n-k; ++i) {
			if (s[i+k-1].st >= cnt) {
				ans[0] = 1;
				ans[1] = i + 1;
				ans[2] = s[i+k-1].nd + 1;
			}
			cnt += a[i] >= x ? 1 : -1;
		}

		return ans;
	};

	int l = 1, r = n;
	while (l < r) {
		int m = l + r + 1 >> 1;

		vi ans = check(m);

		if (ans[0]) l = m;
		else r = m - 1;
	}

	vi ans = check(l);
	cout << l  << ' ' << ans[1] << ' ' << ans[2] << '\n';
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
}

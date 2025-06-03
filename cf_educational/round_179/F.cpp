#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

#define pb push_back

void solve() {
	int p, s; cin >> p >> s;

	int gcd = __gcd(p, s);
	p /= gcd; s /= gcd;

	if (p & 1) p *= 2, s *= 2;

	auto doit = [] (int p, int s) -> vpii {
		int P = p/2;
		int mn = P-1;
		int mx = (P - P/2) * (P/2);

		vpii ans;
		if (s >= mn and s <= mx) {
			int h = P/2; int w = P - h;
			for (int i=1; i<=h; ++i) ans.pb({1, i});
			for (int i=2; i<=w; ++i) ans.pb({i, 1});

			int rem = s - mn, row = 2;
			while (rem > 0) {
				for (int i=2; i<=h and rem > 0; ++i) {
					ans.pb({row, i});
					--rem;
				}

				++row;
			}
		}

		return ans;
	};

	for (int i=1; s*i <= 50000; ++i) {
		vpii ans = doit(p*i, s*i);
		if (!ans.empty()) {
			cout << ans.size() << '\n';
			for (auto [x, y] : ans) cout << x << ' ' << y << '\n';
			return;
		}
	}

	cout << -1 << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;

#define pb push_back

void solve() {
	int n; cin >> n;
	vi a(n); for (int &i: a) cin >> i;

	int l = 2, r = n - 1;
	string ans = "LL";
	bool bigger = a[1] > a[0];
	for (int i=2, x=a[1]; i<n; ++i) {
		if (l == r) ans.pb('R');
		else {
			if (bigger) {
				if (a[l] < x) {
					ans.pb('L');
					x=a[l];
					++l;
				} else if (a[r] < x) {
					ans.pb('R');
					x=a[r];
					--r;
				} else {
					if (a[l] > a[r]) {
						ans.pb('L');
						ans.pb('R');
						x = a[r];
					} else {
						ans.pb('R');
						ans.pb('L');
						x = a[l];
					}
					++l; --r; ++i;
				}
				bigger = false;
			} else {
				if (a[l] > x) {
					ans.pb('L');
					x=a[l];
					++l;
				} else if (a[r] > x) {
					ans.pb('R');
					x=a[r];
					--r;
				} else {
					if (a[l] < a[r]) {
						ans.pb('L');
						ans.pb('R');
						x = a[r];
					} else {
						ans.pb('R');
						ans.pb('L');
						x = a[l];
					}
					++l; --r; ++i;
				}
				bigger = true;
			}
		}
	}

	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
}

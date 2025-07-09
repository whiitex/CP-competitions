#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;

const int INF = 8e18;

void solve() {
    int n; cin >> n;
    vi a(n); for (int &i: a) cin >> i;

	int tot = accumulate(a.begin(), a.end(), 0ll);
	int mx = 0; for (int i: a) mx = max(mx, i);

	if (tot & 1) { cout << "-1\n"; return; }
	if (mx > tot - mx) { cout << "-1\n"; return; }

	vi p(a); for (int i=1; i<n; ++i) p[i] = p[i-1] + a[i];
	vi s(a); for (int i=n-2; i>=0; --i) s[i] = s[i+1] + a[i];

	for (int i=0; i<n-1; ++i) if (p[i] == s[i+1]) {
		cout << 1 << '\n';
		for (int x: a) cout << x << ' ';
		cout << '\n';
		return;
	}

	cout << 2 << '\n';

	int idx = 0, mn = INF;
	for (int i=1; i<n-1; ++i) {
		int diff = abs(p[i] - s[i+1]);
		if (diff % 2 == 0 and diff < mn) {
			mn = diff;
			idx = i;
		}
	}

	vi o(n);
	if (p[idx] > s[idx+1]) {
		int MN = mn/2, i = 0;
		for (; i<=idx and MN > 0; ++i) {
			o[i] = min(a[i], MN);
			a[i] -= o[i];
			MN -= o[i];
		}
		MN = mn/2;
		for (; i<=idx and MN>0; ++i) {
			o[i] = min(a[i], MN);
			a[i] -= o[i];
			MN -= o[i];
		}
	} else {
		int MN = mn/2, i = n-1;
		for (; i>idx and MN > 0; --i) {
			o[i] = min(a[i], MN);
			a[i] -= o[i];
			MN -= o[i];
		}
		MN = mn/2;
		for (; i>idx and MN>0; --i) {
			o[i] = min(a[i], MN);
			a[i] -= o[i];
			MN -= o[i];
		}
	}
	for (int x: o) cout << x << ' '; cout << '\n';

	for (int i: a) cout << i << ' '; cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

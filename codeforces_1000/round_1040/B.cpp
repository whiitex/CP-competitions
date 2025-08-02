#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
    int n, s; cin >> n >> s;
    vi a(n); for (int &i: a) cin >> i;

	vi c(3); for (int i: a) ++c[i];

	int tot = accumulate(a.begin(), a.end(), 0ll);

	if (tot == s) { cout << -1 << '\n'; return; }
	if (tot > s) {
		for (int i: a) cout << i << ' ';
		cout << '\n'; return;
	}

	// tot < s
	s -= tot;

	if (s > 1) cout << -1 << '\n';
	else {
		for (int i=0; i<c[0]; ++i) cout << 0 << ' ';
		cout << 2 << ' ';
		for (int i=0; i<c[1]; ++i) cout << 1 << ' ';
		for (int i=0; i<c[2]-1; ++i) cout << 2 << ' ';
		cout << '\n';
	}

}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

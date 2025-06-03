#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;

vi f(100);

void solve() {
    int n, m; cin >> n >> m;

	vi w(m), l(m), h(m);
	for (int i=0; i<m; ++i) {
		cin >> w[i] >> l[i] >> h[i];
	}

	auto doit = [] (int x, int y, int h, int a1, int a2) -> bool {
		if (a1 > a2) swap(a1, a2);

		if (min(x, y) < a2) return false;
		if (h < a1 + a2) return false;
		return true;
	};

	for (int i=0; i<m; ++i) {
		if (doit(w[i], l[i], h[i], f[n], f[n-1])) cout << 1;
		else if (doit(l[i], h[i], w[i], f[n], f[n-1])) cout << 1;
		else if (doit(w[i], h[i], l[i], f[n], f[n-1])) cout << 1;
		else cout << 0;
	}
	cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	f[1] = 1; f[2] = 2;
	for (int i=3; i<100; ++i) f[i] = f[i-1] + f[i-2];

    int t = 1; cin >> t;
    while (t--) solve();
}

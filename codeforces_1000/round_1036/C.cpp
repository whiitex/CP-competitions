#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
    int n; cin >> n;
    vi a(n); for (int &i: a) cin >> i;

	int mcm = 1;
	for (int i=0; i<n-1; ++i) {
		int g = __gcd(a[i], a[i+1]);

		int x = a[i] / g;
		mcm = (mcm * x) / __gcd(mcm, x);
	}

	cout << mcm << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

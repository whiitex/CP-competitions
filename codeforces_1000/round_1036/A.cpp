#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
    int n; cin >> n;
    vi a(n); for (int &i: a) cin >> i;

	for (int i=0; i<n; ++i) {
		for (int j=i+1; j<n; ++j) {
			if (a[i] > a[j]) {
				cout << "Yes\n2\n";
				cout << a[i] << ' ' << a[j] << '\n';
				return;
			}
		}
	}

	cout << "No\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

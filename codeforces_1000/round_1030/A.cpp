#include <bits/stdc++.h>
using namespace std;


void solve() {
	int n, k; cin >> n >> k;

	for (int i=0; i<k; ++i) cout << '1';
	for (int i=k; i<n; ++i) cout << '0';
	cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

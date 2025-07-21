#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n; cin >> n;

	cout << 1 + (n-1) * 2 << '\n';
	for(int i = 1; i < n; i++){
		cout << i << ' ' << 1 << ' ' << i << '\n';
		cout << i << ' ' << i+1 << ' ' << n << '\n';
	}
	cout << n << ' ' << 1 << ' ' << n << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

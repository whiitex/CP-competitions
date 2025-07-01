#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
	int n, k; cin >> n >> k;
	string s; cin >> s;

	int tot = 0;
	for (char c: s) tot += c == '1';
	if (tot <= k) { cout << "Alice\n"; return; }

	cout << (k * 2 > n ? "Alice" : "Bob") << '\n';
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t = 1; cin >> t;
	while (t--) solve();
}

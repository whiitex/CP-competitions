#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
	string s; cin >> s;

	sort(s.begin(), s.end(), greater<>());
	cout << s << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

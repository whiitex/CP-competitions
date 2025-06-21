#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;

#define pb push_back

void solve() {
	int n, m; cin >> n >> m;

	if (m < n or m > n * (n+1) / 2) { cout << "-1\n"; return; }

	set<int> s; for (int i=1; i<=n; ++i) s.insert(i);

	vi tree;
	while (m) {
		if (m == s.size()) {
			for (int i: s) tree.pb(i);
			break;
		}
		int need = m - (int)s.size() + 1;

		auto it = s.upper_bound(need);
		if (it == s.begin()) {
			cout << "-1\n";
			return;
		}
		--it;
		tree.pb(*it);
		s.erase(it);
		m -= tree.back();
	}

	cout << tree[0] << '\n';
	for (int i=0; i<n-1; ++i) {
		cout << tree[i] << ' ' << tree[i+1] << '\n';
	}
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

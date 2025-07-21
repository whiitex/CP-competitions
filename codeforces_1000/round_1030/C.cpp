#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;


void solve() {
    int n, k; cin >> n >> k;
    vi a(n); for (int &i: a) cin >> i;

	int ans = 0;
	multiset<int> cost;
	for (int x: a) {
		for (int bt=0; bt<62; ++bt) {
			if ((x >> bt) & 1ll) ++ans;
			else {
				cost.insert(1ll << bt);
			}
		}
	}

	while (!cost.empty() and k >= *cost.begin()) {
		k -= *cost.begin();
		cost.erase(cost.begin());
		++ans;
	}

	cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

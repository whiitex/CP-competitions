#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
	int n, q; cin >> n >> q;
	string s; cin >> s;

	vector Q(3, vector<set<int>>(3));
	for (int i=0; i<q; ++i) {
		char a, b; cin >> a >> b;
		Q[a - 'a'][b - 'a'].insert(i);
	}

	vi a(n); for (int i=0; i<n; ++i) a[i] = s[i] - 'a';

	for (int i=0; i<n; ++i) if (a[i]) {
		if (a[i] == 1) {
			if (!Q[1][0].empty()) {
				Q[1][0].erase(Q[1][0].begin());
				a[i] = 0;
			} else {
				auto itc = Q[1][2].begin();
				if (itc == Q[1][2].end()) continue;
				auto ita = Q[2][0].lower_bound(*itc);
				if (ita == Q[2][0].end()) continue;
				a[i] = 0;
				Q[1][2].erase(itc);
				Q[2][0].erase(ita);
			}
		} else if (a[i] == 2) {
			bool tryB = false;
			if (!Q[2][0].empty()) {
				Q[2][0].erase(Q[2][0].begin());
				a[i] = 0;
			} else {
				auto itb = Q[2][1].begin();
				if (itb == Q[2][1].end()) {
					tryB = true;
				} else {
					auto ita = Q[1][0].lower_bound(*itb);
					if (ita == Q[1][0].end()) tryB = true;
					else {
						a[i] = 0;
						Q[2][1].erase(itb);
						Q[1][0].erase(ita);
					}
				}
			}

			if (tryB and !Q[2][1].empty()) {
				Q[2][1].erase(Q[2][1].begin());
				a[i] = 1;
			}
		}
	}


	for (int i=0; i<n; ++i) cout << char(a[i] + 'a'); cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

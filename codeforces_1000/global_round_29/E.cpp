// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef __int128_t lll; typedef long double ld;
typedef pair<int,int> pii; typedef pair<ld,ld> pld;
typedef vector<int> vi; typedef vector<pii> vpii;

#define pb push_back
#define st first
#define nd second

const int MXN = 5e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 8e18;

int mxbit = 32;
void solve() {
    int n, q; cin >> n >> q;
    vi a(n); for (int &i: a) cin >> i;

	int OR = 0; for (int i: a) OR |= i;
	int base = __builtin_popcountll(OR);

	vi cost;
	for (int b=0; b<=31; ++b) if (!((OR >> b) & 1)) {

		int c = 0;
		for (int bt=b; bt>=0; --bt) {

			int pos = -1, bestcost = INF;
			bool good = false;
			for (int i=0; i<n and !good; ++i) {
				if (a[i] >> bt & 1) good = true;

				int mask = (1ll << bt) - 1ll;
				int nwcost = (1ll << bt) - (a[i] & mask);
				if (nwcost < bestcost) {
					bestcost = nwcost;
					pos = i;
				}
			}

			if (!good) {
				a[pos] += bestcost;
				c += bestcost;
			}
		}

		cost.pb(c);
	}

	while (q--) {
		int ops, i=0; cin >> ops;
		while (i < cost.size() and ops >= cost[i]) ops -= cost[i++];
		cout << base + i << '\n';
	}
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1ll; cin >> t;
    while (t--) solve();
}
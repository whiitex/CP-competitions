#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

#define pb push_back
#define st first
#define nd second

const int INF = 8e18;

void solve() {
    int n, k; cin >> n >> k;
    vi a(n); for (int &i: a) cin >> i;
	vi b(n); for (int &i: b) cin >> i;

	vpii all;
	multiset<pii> adj;
	for (int i=0; i<n; ++i) {
		adj.insert({min(a[i], b[i]), max(a[i], b[i])});
		all.pb({min(a[i], b[i]), max(a[i], b[i])});
	}

	int mn = INF;
	for (pii p: all) {
		adj.erase(adj.find(p));
		auto s = adj.lower_bound(pii{p.st, 0ll});
		if (s != adj.end()) {
			int prev = p.nd - p.st + s->nd - s->st;
			vi v{p.nd, s->nd, p.st, s->st};
			sort(v.begin(), v.end());
			int post = v[3] + v[2] - v[0] - v[1];
			mn = min(mn, post - prev);
		}
		adj.insert(p);
	}

	int ans = mn;
	for (int i=0; i<n; ++i) {
		ans += abs(a[i] - b[i]);
	}

	cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

#define pb push_back
#define st first
#define nd second


struct DSU {
	explicit DSU(int n): Par(n), Sz(n, 1) {
		iota(Par.begin(), Par.end(), 0);
	}

	int find(int node) {
		if (Par[node] == node) return node;
		return Par[node] = find(Par[node]);
	}

	void merge(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return;
		if (Sz[a] < Sz[b]) swap(a, b);
		Par[b] = a; Sz[a] += Sz[b];
	}
private: vector<int> Par, Sz;
};


void solve() {
    int n; cin >> n;
	vpii a(n);
	for (int i=0; i<n; ++i) {
		cin >> a[i].st >> a[i].nd;
	}

	struct node {
		int l, r, sz, idx;
	};

	vector<node> all;
	for (int i=0; i<n; ++i) {
		all.pb({a[i].st, a[i].nd, a[i].nd -a[i].st, i+1});
	}
	sort(all.begin(), all.end(), [](const node &a, const node &b) -> bool {
		return a.sz > b.sz;
	});

	DSU dsu(2*n+10);

	vi ans;
	for (node nd: all) {
		if (dsu.find(nd.l) == dsu.find(nd.r)) continue;
		dsu.merge(nd.l, nd.r);
		ans.pb(nd.idx);
	}

	cout << ans.size() << '\n';
	for (int i: ans) cout << i << ' ';
	cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

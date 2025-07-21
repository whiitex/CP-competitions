#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;

#define pb push_back

void solve() {
	int n, k; cin >> n >> k;
	vi p(n); for (int &x : p) cin >> x;
	vi d(n); for (int &x : d) cin >> x;

	int il = -1, ir = -1;
	map<int,int> idxl, idxr, postoi;
	vector<set<int>> modl, modr;

	for (int i=0; i<n; ++i) {
		postoi[p[i]] = i;

		int l = (p[i] - d[i] + k) % k;
		if (!idxl.contains(l)) {
			idxl[l] = ++il;
			modl.pb({});
		}
		modl[idxl[l]].insert(p[i]);

		int r = (p[i] + d[i]) % k;
		if (!idxr.contains(r)) {
			idxr[r] = ++ir;
			modr.pb({});
		}
		modr[idxr[r]].insert(p[i]);
	}

	// dir -> 0: left, 1: right
	auto find = [&] (int pos, int time, int dir) -> int {
		if (dir == 0) {
			int m = (((pos - time) % k) + k) % k;
			if (!idxl.contains(m)) return -1;
			auto it = modl[idxl[m]].upper_bound(pos);
			if (it != modl[idxl[m]].end()) return *it;
		} else {
			int m = (pos + time) % k;
			if (!idxr.contains(m)) return -1;
			auto it = modr[idxr[m]].lower_bound(pos);
			if (it != modr[idxr[m]].begin()) return *(--it);
		}

		return -1;
	};

	vector dp(n, vi(2, 0)); // 0: undefined, 1: loop, 2: exit!

	auto rec = [&] (auto f, int pos, int time, int dir) -> int {
		int saved = dp[postoi[pos]][dir];
		if (saved == 1 or saved == 2) return dp[postoi[pos]][dir];
		if (saved == 3) return 1;

		dp[postoi[pos]][dir] = 3;

		int P = find(pos, time, dir^1);
		if (P == -1) return dp[postoi[pos]][dir] = 2;

		int exit = f(f, P, (time + abs(P - pos)) % k, dir^1);
		return dp[postoi[pos]][dir] = exit;
	};

	for (int i=0; i<n; ++i) {
		if (!dp[i][0]) rec(rec, p[i], d[i], 0);
		if (!dp[i][1]) rec(rec, p[i], d[i], 1);
	}

	int q; cin >> q; while (q--) {
		int x; cin >> x;

		int P;
		if (postoi.contains(x) and d[postoi[x]] == 0) P = x;
		else P = find(x, 0, 0);

		cout << (dp[postoi[P]][0] == 2 ? "Yes" : "No") << '\n';
	}
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

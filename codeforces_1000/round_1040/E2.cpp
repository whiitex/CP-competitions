#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;

#define pb push_back

int ask(vi a) {
	cout << "? " << a.size() << ' ';
	for (int i: a) cout << i << ' ';
	cout << endl; cout.flush();
	int x; cin >> x; return x;
}

void answer(string &s) {
	cout << "! " << s << endl; cout.flush();
}

void solve() {
    int n; cin >> n;

	vi a(n); iota(a.begin(), a.end(), 1);
	int X = ask(a), L = -1, R = -1;

	if (X == 0) L = n, R = 1;
	else {
		// find rightmost )
		int l=1, r=n;
		while (l < r) {
			int m = l + r >> 1;
			vi b; for (int i=1; i<=m; ++i) b.pb(i);
			if (ask(b) == X) r = m;
			else l = m + 1;
		} R = l;

		// find leftmost (
		l = 1, r = R-1;
		while (l < r) {
			int m = l + r + 1 >> 1;
			vi b; for (int i=m; i<=R; ++i) b.pb(i);
			if (ask(b) == X) l = m;
			else r = m - 1;
		} L = l;
	}

	string s(n+1, ')');

	int tot = 0;
	vi tmp, pos(8);
	for (int bt=7; bt>=0; --bt) {
		pos[bt] = (int)tmp.size();
		tmp.pb(-1); tmp.pb(R);

		int len = 1ll << bt;
		for (int i=1; i<len; ++i) {
			tmp.pb(L); tmp.pb(R);
		}
		tmp.pb(R);

		tot += (len - 1) * len / 2;
	}

	int x = 1;
	for (int rep=0; rep<(n+7) / 8; ++rep) {

		vi idxs;
		for (int bt=0; bt<8; ++bt) {
			idxs.pb(x);
			tmp[pos[bt]] = x;
			x %= n; ++x;
		}

		X = ask(tmp); X -= tot;

		int i = 0;
		while (X) {
			if (X & 1) s[idxs[i]] = '(';
			X >>= 1; ++i;
		}
	}

	string ans = s.substr(1, n);
	answer(ans);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

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

void solve() {
	int k, n; cin >> k >> n;

	if (n == (1 << k)) { cout << 0 << '\n' << '\n'; return; }

	int A = 1 << k, B = 1 << k;
	vi ans;
	auto one = [&]() {
		ans.pb(1);
		B += A/2;
		A /= 2;
	};
	auto two = [&]() {
		ans.pb(2);
		A += B/2;
		B /= 2;
	};
	// bool invert = 0;
	// if (n > (1 << k)) n = (1 << k+1) - n, invert = 1;

	auto rec = [&] (auto f, int a, int b, vi v) -> vi {
		if (v.size() > 12) return vi(122, 1);
		if (a == n) return v;

		vi vec1(v); vec1.pb(1);
		vi v1 = f(f, a/2, b + a/2, vec1);

		vi vec2(v); vec2.pb(2);
		vi v2 = f(f, a + b/2, b/2, vec2);

		if (v1.size() < v2.size()) return v1;
		return v2;
	};

	vi a = rec(rec, A, B, ans);
	if (a.size() > 12) cout << -1 << '\n';
	else {
		cout << a.size() << '\n';
		for (int i: a) cout << i << ' ';
		cout << '\n';
	}
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

#define pb push_back
#define st first
#define nd second

constexpr int MXN = 5e5 + 5;
constexpr int MOD = 1e9 + 7;
constexpr int INF = 8e18;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int uniform_distr(int a, int b) {
	return uniform_int_distribution<int>(a, b)(rng);
}


void solve() {
	int x, y; cin >> x >> y;

	int bestp = 0, bestq = 0, bestvalue = x + y;
	auto calc = [&](int p, int q) -> void {
		if ((p & q) != 0) return;
		int value = abs(x - p) + abs(y - q);
		if (value < bestvalue) {
			bestvalue = value;
			bestp = p; bestq = q;
		}
	};


	// try maximize q < y (and p = x)
	int p = x, q = 0;
	for (int bit=30; bit>=0; --bit) {
		if ((p >> bit) & 1) continue;

		calc(p, q + (1 << bit));
		if (q + (1 << bit) < y) {
			q += (1 << bit);
		}
	}

	// try maximize p < x (and q = y)
	p = 0, q = y;
	for (int bit=30; bit>=0; --bit) {
		if ((q >> bit) & 1) continue;

		calc(p + (1 << bit), q);
		if (p + (1 << bit) < x) {
			p += (1 << bit);
		}
	}

	// cerr << bestvalue << '\n';
	cout << bestp << ' ' << bestq << '\n';
}

void solve2() { }

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s = "f"; // cin >> s;
	int t = 1; cin >> t;
	while (t--) s[0] == 'f' ? solve() : solve2();
}
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
    int n; cin >> n;
    vi a(n); for (int &i: a) cin >> i;

	bool ok = 1;
	for (int i=1; i<n; ++i) if (a[i] < a[i-1]) ok = 0;
	if (ok) { cout << "-1\n"; return; }

	set<int> D;
	vi b(a); sort(b.begin(), b.end());
	for (int i=0; i<n; ++i) {
		D.insert(b[n-1] - b[i]);
		D.insert(b[i] - b[0]);
	}

	set<int> nop;
	for (int i=0; i<n; ++i) if (a[i] != b[i]) {
		nop.insert(a[i]);
		nop.insert(b[i]);
	}

	auto clear = [&](int x) {
		nop.erase(x);
	};

	int l = -1, r = n, d = INF;
	while (!nop.empty()) {
		d = *D.rbegin(); D.erase(D.find(d));

		while (r-1 >= 0 and abs(b[0] - b[r-1]) >= d) {
			--r; clear(b[r]);
		}
		while (l+1 < n and abs(b[n-1] - b[l+1]) >= d) {
			++l; clear(b[l]);
		}
	}

	cout << d << '\n';
}

void solve2() { }

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s = "f"; // cin >> s;
	int t = 1; cin >> t;
	while (t--) s[0] == 'f' ? solve() : solve2();
}
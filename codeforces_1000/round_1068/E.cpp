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


pii ask(int x, int y) {
	cout << "? " << x << ' ' << y << endl;
	int a, b; cin >> a >> b; return {a, b};
}

void solve() {
    int n; cin >> n;
	vi a(n+1), pos(n+1);
	for (int i=1; i<=n; ++i) {
		cin >> a[i];
		pos[a[i]] = i;
	}

	for (int i=1; i<=n/2; ++i) {
		while (pos[i] != i or pos[n-i+1] != n-i+1) {
			int x, y;
			if (pos[i] != i) x = i, y = pos[i];
			else x = n-i+1, y = pos[n-i+1];

			auto [w, q] = ask(x, y);
			swap(a[w], a[q]);
			pos[a[w]] = w;
			pos[a[q]] = q;
		}
	}


	cout << "!" << endl;
}

void solve2() { }

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s = "f"; // cin >> s;
	int t = 1; cin >> t;
	while (t--) s[0] == 'f' ? solve() : solve2();
}
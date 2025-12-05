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
    int n, k; cin >> n >> k;
    vi a(n); for (int &i: a) cin >> i;

	sort(a.begin(), a.end());
	map<int,int> f; for (int i: a) ++f[i];
	set<int> A; for (int i: a) A.insert(i);

	vi ans;
	map<int,int> done;

	for (int i: A) if (!done[i]) {
		ans.pb(i);
		int mul = i;

		while (mul <= k) {
			if (!f[mul]) { cout << -1 << '\n'; return; }
			done[mul] = 1;
			mul += i;
		}
	}


	cout << ans.size() << '\n';
	for (int i: ans) cout << i << ' ';
	cout << '\n';
}

void solve2() { }

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s = "f"; // cin >> s;
	int t = 1; cin >> t;
	while (t--) s[0] == 'f' ? solve() : solve2();
}
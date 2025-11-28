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
	vi q(n); for (int &i: q) cin >> i;
	vi r(n); for (int &i: r) cin >> i;

	sort(q.begin(), q.end(), greater());
	sort(r.begin(), r.end());


	auto compute = [&k](int q, int r) -> bool {
		int y = r + 1;
		int x = q * y + r;
		return x <= k and y <= k;
	};

	int op = 0, i = 0;
	for (int div: q) {
		if (compute(div, r[i])) {
			++op;
			++i;
		}
	}

	cout << op << '\n';
}
void solve2() { }

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s = "f"; // cin >> s;
	int t = 1; cin >> t;
	while (t--) s[0] == 'f' ? solve() : solve2();
}
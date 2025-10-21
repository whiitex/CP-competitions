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

vi divs(MXN, 1), primes;

void solve() {
    int n; cin >> n;
    vi a(n); for (int &i: a) cin >> i;
	vi b(n); for (int &i: b) cin >> i;


	auto work = [&] (vi a) -> int {
		set<int> pr;
		int one = 0;
		for (int x: a) { // check 0
			int y = x + 1;
			set<int> p;
			while (x > 1) {
				if (pr.contains(divs[x])) return 0;
				p.insert(divs[x]);
				x /= divs[x];
			}

			while (y > 1) {
				if (pr.contains(divs[y])) one = 1;
				y /= divs[y];
			}

			for (int P: p) pr.insert(P);
		}

		return (one ? 1 : 2);
	};

	int ans1 = work(a);
	reverse(a.begin(), a.end());
	int ans2 = work(a);

	cout << min(ans1, ans2) << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	for (int i=2; i<MXN; ++i) if (divs[i] == 1) {
		for (int j=i; j<MXN; j+=i) {
			if (divs[j] == 1) divs[j] = i;
		}
	}

    int t = 1; cin >> t;
    while (t--) solve();
}

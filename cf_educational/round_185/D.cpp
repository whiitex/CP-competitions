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

int val(char c) {
	if (c == 'I') return 1;
	if (c == 'V') return 5;
	if (c == 'X') return 10;
	return -1;
}

void solve() {
	int n, q; cin >> n >> q;
	string s; cin >> s;

	int value = 0;
	for (int i=0; i<n; ++i) if (s[i] != '?') {
		if (val(s[i]) > 1) { value += val(s[i]); continue; }

		// its 'I'
		if (i < n-1 and s[i+1] == '?') { ++value; continue; }

		if (i == n-1) value += val(s[i]);
		else value += (val(s[i]) < val(s[i+1]) ? -1 : 1);
	}

	int pairs = 0, big = 0, small = 0, tot = 0, both = 0;
	for (int i=0; i<n; ++i) if (s[i] == '?') {
		int j = i;
		while (j + 1 < n and s[j+1] == '?') j++;

		int cnt = j - i + 1;
		tot += cnt;

		if (j + 1 < n and val(s[j+1]) > 1) ++big, --cnt;
		if (i > 0 and s[i-1] == 'I') ++small, --cnt;

		if (cnt == -1) ++both, --big, --small;

		pairs += cnt / 2;

		i = j;
	}
	int none = tot - pairs * 2 - big - small - both;

	while (q--) {
		int one, fiv, ten; cin >> ten >> fiv >> one;

		int BOTH = both, SMALL = small;

		int ans = value, rem = tot;

		int onebig = min(big, one);
		ans -= onebig, one -= onebig, rem -= onebig;

		int onepairs = min(one, pairs);
		ans += onepairs, one -= onepairs, rem -= onepairs;

		int oneboth = min(BOTH, one);
		ans -= oneboth, one -= oneboth, rem -= oneboth, BOTH -= oneboth;

		int onenone = min(none, one);
		ans += onenone, one -= onenone, rem -= onenone;

		int rempair = min(onepairs, one);
		ans += rempair, rem -= rempair, one -= rempair, onepairs -= rempair;

		int onesmall = min(small, one);
		ans += onesmall, one -= onesmall, rem -= onesmall, SMALL -= onesmall;


		ans -= 2 * onepairs;

		int used = 0;
		ans += 5 * min(fiv, rem), used += min(fiv, rem);
		rem -= min(fiv, rem);
		ans += 10 * min(ten, rem), used += min(ten, rem);
		rem -= min(ten, rem);

		assert(rem == 0);

		ans -= 2 * min(SMALL, used);
		used -= min(SMALL, used);
		ans -= 2 * min(BOTH, used);

		cout << ans << '\n';
	}
}

void solve2() { }

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s = "f"; // cin >> s;
	int t = 1; cin >> t;
	while (t--) s[0] == 'f' ? solve() : solve2();
}
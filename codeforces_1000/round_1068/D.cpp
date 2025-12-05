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

string tobitstring(int x) {
	string s;
	while (x) {
		s.pb((x & 1) + '0');
		x >>= 1;
	}
	reverse(s.begin(), s.end());
	return s;
}

void solve() {
	int n, k; cin >> n >> k;

	if (k == 0) { cout << "0\n"; return; }

	while(n % 2 == 0) n >>= 1;

	vi a;
	string ns = tobitstring(n);
	for (int i=0; i<(int)ns.size(); ++i) {
		int j = i;
		while (j + 1 < (int)ns.size() && ns[j + 1] == ns[i]) j++;
		a.pb(j - i + 1);
		i = j;
	}

	int need = 0;
	for (int i=1; i<(int)a.size(); i+=2) need += a[i];
	if (k > need) {

		int tot = 0;
		for (int x: a) tot += x;

		cout << tot + (k - need - 1) << '\n';
		return;
	}

	int ans = k;

	int masklen = ((int)a.size()) >> 1;

	if (masklen == 0) ans = a[0] + k - 1;


	for (int mask = 0; mask < (1 << masklen); ++mask) {

		string ms = tobitstring(mask);
		reverse(ms.begin(), ms.end());
		while ((int)ms.size() < masklen) ms.pb('0');
		reverse(ms.begin(), ms.end());

		int need = 0;
		for (int i=0; i<(int)ms.size(); ++i) {
			if (ms[i] == '1') need += a[i * 2 + 1];
		} if (need > k) continue;

		vi G;
		for (int i=0; i<(int)ms.size(); ++i) {
			if (ms[i] == '1') {
				int gain = a[2 * i];
				int j = i;
				while (j < (int)ms.size() and ms[j] == '1') {
					gain += a[2 * (j + 1)];
					gain += a[2 * j + 1];
					j++;
				}
				G.pb(gain);
				i = j - 1;
			} else {
				if (i == (int)ms.size() -1 or ms[i + 1] == '0') {
					G.pb(a[2 * (i+1)]);
				}
				if (i == 0) G.pb(a[0]);
			}
		}

		int nans = 0, used = need, j = G.size() - 1;
		sort(G.begin(), G.end());
		while (used < k and j >= 0) {
			nans += G[j];
			used++; --j;
		}

		nans += k - used;
		ans = max(ans, nans);
	}

	cout << ans << '\n';
}

void solve2() { }

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s = "f"; // cin >> s;
	int t = 1; cin >> t;
	while (t--) s[0] == 'f' ? solve() : solve2();
}
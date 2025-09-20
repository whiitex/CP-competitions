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
	int n; cin >> n;
	vi a(n); for (int &i: a) cin >> i;

	map<int, int> cnt;
	for (int x : a) cnt[x]++;

	map<int,int> f;
	for (auto [val, freq] : cnt) {
		f[freq] += val;
	}

	set<pii> contrib;
	for (auto [freq, cnt]: f) contrib.insert({-freq, cnt});

	int alice = 0, bob = 0, isalice = 1;
	for (auto [freq, cnt]: contrib) {
		freq = -freq;

		int val1 = (cnt + 1) / 2;
		int val2 = cnt / 2;

		if (isalice) alice += val1 * freq, bob += val2 * freq;
		else bob += val1 * freq, alice += val2 * freq;

		if (cnt & 1) isalice ^= 1;
	}

	cout << alice << ' ' << bob << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

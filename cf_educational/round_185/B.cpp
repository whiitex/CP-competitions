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

	int N = n;
	sort(a.begin(), a.end(), greater());

	while (a.back() == 0) a.pop_back();
	n = a.size();

	int cnt = 0;
	for (int i=0; i<n; ++i) {
		cnt += a[i] - 1;
	}

	cnt = min(cnt, N-1);

	cout << n - (N-1 - cnt) << '\n';
}

void solve2() { }

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s = "f"; // cin >> s;
	int t = 1; cin >> t;
	while (t--) s[0] == 'f' ? solve() : solve2();
}
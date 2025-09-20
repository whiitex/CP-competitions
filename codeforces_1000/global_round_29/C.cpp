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
	string s; cin >> s;

	if (n == 1) { cout << "YES\n"; return; }

	vector dp(n, array<int,3>()); // rabb left, rabb right, pointed pot
	if (s[0] == '0') {
		dp[0][0] = 1;
		dp[0][1] = 0;
		if (s[1] == '1') dp[1][2] = 1;
	}


	bool no = false;
	for (int i=1; i<n and !no; ++i) {
		if (s[i] == '1') {
			if (dp[i-1][2] == 2 and s[i-1] == '1' or dp[i][2] == 2 and i == n-1) {
				no = true;
			}
			continue;
		}

		if (s[i-1] == '0') {
			if (i < n-1 and s[i+1] == '1') dp[i+1][2] = 1;
			dp[i][0] = 1;
			dp[i][1] = 1;
		} else {
			if (dp[i-1][2] == 2) {
				dp[i][0] = 1;
			} else if (dp[i-1][2] == 1) {
				dp[i][1] = dp[i][0] = 1;
				if (i < n-1 and s[i+1] == '1') dp[i+1][2] = 1;
			} else {
				if (i < n-1) dp[i+1][2] = 2;
				// else no = true;
			}
		}
	}

	cout << (no ? "NO\n" : "YES\n");
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

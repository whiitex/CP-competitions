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
	int x, y; cin >> x >> y;

	if (y > x) cout << 2 << '\n';
	else if (y > 1 and x-y > 1) cout << 3 << '\n';
	else cout << -1 << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

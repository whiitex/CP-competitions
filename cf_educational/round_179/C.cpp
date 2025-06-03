#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

#define pb push_back
#define st first
#define nd second

const int INF = 8e18;

void solve() {
    int n; cin >> n;
    vi a(n); for (int &i: a) cin >> i;

	vpii b;
	for (int i=0; i<n; ++i) {
		int j = i+1;
		while (j < n and a[j] == a[i]) ++j;
		b.pb({a[i], j-i});
		i = j-1;
	}

	int ans = INF;
	for (int i=0, begin=0, end=n; i<b.size(); ++i) {
		end -= b[i].nd;
		ans = min(ans, b[i].st * (begin + end));
		begin += b[i].nd;
	}

	cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

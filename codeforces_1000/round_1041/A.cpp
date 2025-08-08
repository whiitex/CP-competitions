#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
    int n; cin >> n;
    vi a(n); for (int &i: a) cin >> i;

	set<int> st;
	for (int i: a) if (i != -1) st.insert(i);

	if (st.size() > 1 or !st.empty() and *st.begin() == 0) cout << "No\n";
	else cout << "Yes\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

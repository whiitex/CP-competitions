#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

#define st first
#define nd second

void solve() {
    int n, k; cin >> n >> k;
    vi vec(n); for (int &i: vec) cin >> i;

    vpii mods(k);
    for (int i=0; i<n; ++i) {
        mods[vec[i] % k].st++;
        mods[vec[i] % k].nd = i+1;
    }

    int ok = 0, ans;
    for (auto [cnt, index]: mods) {
        if (cnt == 1) ok = 1, ans = index;
    }

    if (!ok) cout << "NO\n";
    else cout << "YES\n" << ans << '\n';

}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

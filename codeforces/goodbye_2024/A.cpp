#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef __int128_t lll; typedef long double ld;
typedef pair<int,int> pii; typedef pair<ld,ld> pld;
typedef vector<int> vi; typedef vector<pii> vpii;

#define pb push_back
#define st first
#define nd second

const int MAXN = 5e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 1e18;

void solve() {
    int n; cin >> n;
    vi vec(n); for (int &i: vec) cin >> i;
    // sort (vec.begin(), vec.end());

    for (int i=1; i<n; ++i) {
        int a = min(vec[i], vec[i-1]);
        int b = max(vec[i], vec[i-1]);
        if (b < 2*a) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

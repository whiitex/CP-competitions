#include <bits/stdc++.h>

using namespace std;

typedef __int128_t lll; typedef long long ll; typedef long double ld;
typedef pair<int,int> pii; typedef pair<ll,ll> pll;
typedef vector<int> vi; typedef vector<ll> vll; typedef vector<pii> vpii; typedef vector<pll> vpll;

#define pb push_back
#define f first
#define s second


void solve() {
    int n; cin >> n;
    string s; cin >> s;

    int i=0;
    while (i<n and s[i] == 'W') ++i;
    if (i == n) cout << 0 << '\n';
    else {
        int j = n-1;
        while (s[j] == 'W') --j;
        cout << j-i+1 << '\n';
    }

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}

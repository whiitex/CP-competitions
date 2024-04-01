#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

#define pb push_back

void solve() {
    int n, m; cin >> n >> m;
    vi vec(n); for(int& i: vec) cin >> i;
    string s; cin >> s;

    int i=-1;
    for (char c: s) if (c == 'L') ++i;
    int j = i+1;

    ll mul = 1;
    vll ans;
    for (int x=n-1; x>=0; --x) {
        if (s[x] == 'L') {
            mul = (mul * vec[i]) % m;
            ans.pb(mul);
            --i;
        } else {
            mul = (mul * vec[j]) % m;
            ans.pb(mul);
            ++j;
        }
    }

    std::reverse(ans.begin(), ans.end());
    for (int a: ans) cout << a << ' ';
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}

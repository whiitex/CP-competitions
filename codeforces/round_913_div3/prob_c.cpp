#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    map<char,int> m;

    for (int i=0; i<n; ++i) {
        if (m.find(s[i]) == m.end())
            m.insert({s[i], 1});
        else m[s[i]]++;
    }

    int most = 0;
    for (auto p: m)
        most = max(most, p.second);

    if (most > n-most)
        cout << most - (n-most) << '\n';
    else cout << n % 2 << '\n';


}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

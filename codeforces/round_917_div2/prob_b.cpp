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
    map<char,int> mp;
    for (int i=0; i<n; ++i) {
        if (mp.find(s[i]) == mp.end())
            mp.insert({s[i], 1});
        else mp[s[i]]++;
    }

    ll ans = mp.size();
    for (int i=n-1; i>=0; --i) {
        mp[s[i]]--;
        if (mp[s[i]] == 0) mp.erase(s[i]);
        ans += mp.size();
    }

    cout << ans << '\n';
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
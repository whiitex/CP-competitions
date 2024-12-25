#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;
typedef pair<int,int> pii;

#define pb push_back

int to_int (string& s) {
    int ans = 0;
    for (char c: s) {
        ans *= 10;
        ans += c - '0';
    } return ans;
}

void solve() {
    int n; cin >> n;
    vi vec(n); for (int &i: vec) cin >> i;

    map<pii, int> mp;
    auto f = [&] (auto f, int x, int t) -> int {
        if (mp[{x, t}]) return mp[{x, t}];
        if (t == 0) return 1;

        if (x == 0) {
            int val = f(f, 1, t-1);
            mp[{x, t}] = val;
            return val;
        }
        if (to_string(x).size() % 2 == 0) {
            string vals = to_string(x);
            string s1 = vals.substr(0, vals.size()/2);
            string s2 = vals.substr(vals.size()/2);
            int n1 = to_int(s1), n2 = to_int(s2);
            int val1 = f(f, n1, t-1), val2 = f(f, n2, t-1);
            mp[{x, t}] = val1 + val2;
            return val1 + val2;
        }
        int val = f(f, x*2024, t-1);
        mp[{x, t}] = val;
        return val;
    };

    int ans = 0, times = 75;
    for (int i: vec) ans += f(f, i, times);
    cout << mp.size() << '\n';

    cout << ans << '\n';
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();
}

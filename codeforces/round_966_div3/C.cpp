#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

const int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vi vec(n); for (int &i: vec) cin >> i;

    int m; cin >> m;
    while (m--) {
        string s; cin >> s;
        if (s.size() != n) {
            cout << "NO\n";
            continue;
        }

        bool ok = true;
        vector<int> letters(100, MOD);
        unordered_map<int, char> mp;
        for (int i=0; i<n; ++i) {
            if (letters[s[i] - 'a'] != MOD and letters[s[i] - 'a'] != vec[i]) {
                ok = false;
                break;
            }

            if (mp.find(vec[i]) != mp.end() and mp[vec[i]] != s[i]) {
                ok = false;
                break;
            }


            if (letters[s[i] - 'a'] == MOD) {
                letters[s[i] - 'a'] = vec[i];
                mp[vec[i]] = s[i];
            }
        }

        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }



}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

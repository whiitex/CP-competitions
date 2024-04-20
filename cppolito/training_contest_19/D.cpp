#include <bits/stdc++.h>

using namespace std;

bool is_available(map<char,char> &mp, char c, char si) {
    while (mp.find(c) != mp.end()) {
        c = mp[c];
        if (c == si) return false;
    } return true;
}

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    map<char,char> mp;
    vector<bool> binded(200, 0);
    vector<bool> assigned(200, 0);

    int count = 0;
    for (int i=0; i<n; ++i) {
        if (not binded[s[i]]) {

            char c = 'a';
            if (count == 25)
                while (assigned[c]) ++c;
            else
                while (assigned[c] or !is_available(mp, c, s[i]) or c == s[i])
                    ++c;

            mp.insert({s[i], c});
            ++count;
            if (count == 26) break;
            binded[s[i]] = 1;
            assigned[c] = 1;
        }
    }

    string t;
    for (char k: s) t.push_back(mp[k]);
    cout << t << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}

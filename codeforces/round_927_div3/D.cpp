#include <bits/stdc++.h>

using namespace std;

#define pb push_back

void solve() {
    int n;
    cin >> n;
    char trump;
    cin >> trump;

    vector<string> vec, bonus;
    for (int i = 0; i < 2 * n; ++i) {
        string s;
        cin >> s;
        std::reverse(s.begin(), s.end());
        if (s[0] == trump) bonus.pb(s);
        else vec.pb(s);
    }

    std::sort(vec.begin(), vec.end());
    std::sort(bonus.begin(), bonus.end());

    vector<string> ans;

    int j = 0;
    for (int i = 0; i < vec.size(); ++i) {
        auto first = vec[i];
        if (i + 1 < vec.size() and vec[i + 1][0] == first[0]) {
            std::reverse(first.begin(), first.end());
            std::reverse(vec[i + 1].begin(), vec[i + 1].end());
            ans.pb(first + " " + vec[i + 1]);
            ++i;
        } else if (j < bonus.size()) {
            std::reverse(first.begin(), first.end());
            std::reverse(bonus[j].begin(), bonus[j].end());
            ans.pb(first + ' ' + bonus[j]);
            ++j;
        } else {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }

    for (auto q: ans) cout << q << '\n';

    for (; j < bonus.size(); j += 2) {
        std::reverse(bonus[j + 1].begin(), bonus[j + 1].end());
        std::reverse(bonus[j].begin(), bonus[j].end());
        cout << bonus[j] << ' ' << bonus[j+1] << '\n';
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

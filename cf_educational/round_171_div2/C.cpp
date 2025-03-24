#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
    int n; cin >> n;
    string day; cin >> day;
    day = '$' + day;

    int ans = (n * (n+1)) / 2;
    deque<int> cst;
    for (int i=n; i>0; --i) {
        if (day[i] == '0' and !cst.empty()) {
            ans -= cst[0];
            cst.pop_front();
        } else if (day[i] == '1') {
            cst.push_back(i);
        }
    }

    int take = cst.size()/2;
    for (int i=0; i<take; ++i) ans -= cst[i];

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

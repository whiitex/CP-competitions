#include <bits/stdc++.h>

using namespace std;

#define pb push_back

void solve() {
    int n; cin >> n;
    string row[2];
    cin >> row[0] >> row[1];
    string ans;
    ans.pb(row[0][0]); // push the first position (1,1)

    // Find the shortest (lex) path
    int turn;   // index in which it goes downward
    bool done = false;  // has already gone downward?
    
    for (int i=0; i<n; ++i) {
        if (not done and i == n-1) { // hit only if we get to pos (1,n)
            ans.pb(row[1][n-1]);
            turn = n-1;
            continue;
        }

        if (row[0][i+1] == '1' and row[1][i] == '0' and not done) {
            done = true;
            ans.pb(row[1][i]);
            turn = i;
        } else {
            if (done) ans.pb(row[1][i]);
            else ans.pb(row[0][i+1]);
        }
    }

    cout << ans << '\n';

    // Count paths
    int num = 1;
    for (int i=turn; i>0; --i) {
        if (row[0][i] == row[1][i-1]) ++num;
        else break;
    }

    cout << num << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}

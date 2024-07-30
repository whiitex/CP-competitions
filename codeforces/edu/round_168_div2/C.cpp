#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    int open = 0;
    for (int i=0; i<n; ++i) {
        if (s[i] == '_') {
            if (open == 0) {
                ++open;
                s[i] = '(';
            } else {
                --open;
                s[i] = ')';
            }
        } else if (s[i] == '(') ++open;
        else --open;
    }

    stack<int> st;
    int ans = 0;
    for (int i=0; i<n; ++i) {
        if (s[i] == '(') st.push(i);
        else {
            int top = st.top(); st.pop();
            ans += i - top;
        }
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve() {
    string s; cin >> s;

    int up=0, low=0;
    for (int i= s.length()-1; i>=0; --i) {
        if (s[i] == 'b') {
            ++low;
            s[i] = '_';
        } else if (s[i] == 'B') {
            ++up;
            s[i] = '_';
        } else {
            if (low > 0 and islower(s[i])) {
                --low;
                s[i] = '_';
            }
            else if (up > 0 and isupper(s[i])) {
                --up;
                s[i] = '_';
            }
        }
    }

    for (char c: s) if (c != '_')
        cout << c;
    cout << '\n';
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

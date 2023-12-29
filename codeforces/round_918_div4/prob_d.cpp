#include <bits/stdc++.h>

using namespace std;

#define lll __int128_t
#define ll long long
#define ld long double

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;


void solve() {
    int n; cin >> n;
    string s; cin >> s;

    int last=-1;
    auto dot = [&]() {cout << '.';};
    for (int i=0; i<n-3; ++i) {
        if (s[i+3] == 'a' or s[i+3] == 'e') {
            cout << s[i] << s[i + 1];
            dot();
            last = i+1;
            i += 1;
        } else {
            cout << s[i] << s[i + 1] << s[i+2];
            dot();
            last = i+2;
            i += 2;
        }
    }
    if (n-last-1 == 2) {
        cout << s[n-2] << s[n-1];
    } else {
        cout << s[n-3] << s[n-2] << s[n-1];
    }

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

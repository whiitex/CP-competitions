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
    char zero = s[0];
    char one = s[1];

    char chars[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    char ints[] = {'1','2','3','4','5','6','7','8'};

    // row
    for (char c: chars)
        if (c != zero) {
            s[0] = c;
            cout << s << '\n';
        }


    // col
    s[0] = zero;
    for (char i: ints)
        if (i != one) {
            s[1] = i;
            cout << s << '\n';
        }
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
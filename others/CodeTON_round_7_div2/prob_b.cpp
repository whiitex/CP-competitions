#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int sol = 0, i=n-1;
    int b, a;

    while (i >= 0) {
        b = 0, a = 0;
        while (s[i] == 'B' and i>=0) {
            ++b;
            --i;
        }
        while (s[i] == 'A' and i>=0) {
            ++a;
            --i;
        }
        if (a!=0 and b!=0 and sol !=0) ++sol;
        if (a!=0 and b!=0)
            sol += a+b-1;
    }
    cout << sol << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

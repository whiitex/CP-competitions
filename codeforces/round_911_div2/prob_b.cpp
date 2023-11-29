#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    int A=0, B=0, C=0;

    // A
    if (b == c or (b%2 == c%2 and a>0))
        A = 1;

    // B
    if (a == c or (a%2 == c%2 and b>0))
        B = 1;

    // C
    if (a == b or (a%2 == b%2 and c>0))
        C = 1;

    if (a == 0 and b == 0 and c == 0)
        cout << "0 0 0" << '\n';
    else cout << A << ' ' << B << ' ' << C << ' ' << '\n';

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

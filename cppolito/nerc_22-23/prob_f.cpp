#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;


void solve() {
    int n, a, b; cin >> n >> a >> b;

    int draws = 0;

    if (n==1) {
        draws = a==b;
        cout << draws << '\n';
        cout << a << ':' << b << '\n';
    } else {
        if (a + b >= n)
            draws = 0;
        else draws = n - a - b;

        cout << draws << '\n';
        int repeat = draws;
        while (repeat--) cout << "0:0" << '\n';

        if (n-draws>0) {
            if (a < b) {
                for (int i = 0; i < n - draws - 1; ++i) {
                    if (a > 0) {
                        cout << "1:0" << '\n';
                        --a;
                    } else {
                        cout << "0:1" << '\n';
                        --b;
                    }
                }
                cout << a << ':' << b << '\n';
            } else {
                for (int i = 0; i < n - draws - 1; ++i) {
                    if (b > 0) {
                        cout << "0:1" << '\n';
                        --b;
                    } else {
                        cout << "1:0" << '\n';
                        --a;
                    }
                }
                cout << a << ':' << b << '\n';
            }
        }
    }


}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t=1;
//    cin >> t;
    while (t--) {
        solve();
    }
}

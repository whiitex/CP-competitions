#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve() {
    int n, k; cin >> n >> k;
    while (k>0) {
        if (n%10 == 0)
            n /= 10;
        else --n;
        --k;
    }
    cout << n << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
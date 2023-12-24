#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;


void solve() {
    int n; cin >> n;
    vector<int> vec(n);
    int neg = 0;
    bool zero = false;
    for (int i=0; i<n; ++i) {
        cin >> vec[i];
        if (vec[i] < 0) neg++;
        if (vec[i] == 0) zero = true;
    }

    if (neg % 2 == 0 and !zero) {
        cout << "1\n1 0\n";
    } else {
        cout << "0\n";
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
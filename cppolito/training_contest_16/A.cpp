#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        ll n, s; cin >> n >> s;
        cout << s/(n*n) << '\n';
    }
}

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        ll sum = 0, a;
        for (int i=0; i<n; ++i) {
            cin >> a;
            sum += abs(a);
        }
        cout << sum << '\n';
    }

}

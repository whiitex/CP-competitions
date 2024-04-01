#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {

        int a, b, n; cin >> a >> b >> n;
        if (a > b) swap(a,b);
        int count = 0;
        while (b <= n) {
            a += b;
            swap(a,b);
            ++count;
        }

        cout << count << '\n';
    }
}

#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> vec(n); for (int &i: vec) cin >> i;
        std::sort(vec.begin(), vec.end());

        int ans = 1;
        vec[0]++;

        for (int& i: vec) ans *= i;
        cout << ans << '\n';
    }
}

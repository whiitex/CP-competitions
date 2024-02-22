#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vi vec(n); for (int& i: vec) cin >> i;
        std::sort(vec.begin(), vec.end());

        if (n == 1) {cout << 0 << '\n'; continue;}

        int longest = -1;
        for (int i=0; i<n; ++i) {
            int j = i+1;
            while (j<n and vec[j] - vec[j-1] <= k) ++j;
            longest = max(longest, j-i);
            i = j-1;
        }

        cout << n - longest << '\n';
    }
}

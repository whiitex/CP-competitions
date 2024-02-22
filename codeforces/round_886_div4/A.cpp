#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        vi vec(3); for (int &i: vec) cin >> i;
        std::sort(vec.begin(), vec.end());
        if (vec[1] + vec[2] < 10) cout << "No\n";
        else cout << "Yes\n";
    }
}

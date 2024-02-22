#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;

ll fill(vi &vec, int h) {
    ll water = 0;
    for (int i: vec)
        water += max(0, h-i);
    return water;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n, x; cin >> n >> x;
        vi vec(n); for (int &i: vec) cin >> i;

        ll l=1, r=2e9;
        while (l < r) {
            int mid = l+r+1 >> 1;
            ll water = fill(vec, mid);

            if (water > x)
                r = mid-1;
            else
                l = mid;
        }

        cout << l << '\n';
    }
}

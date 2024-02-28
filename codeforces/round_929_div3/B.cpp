#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int solve() {
    int n; cin >> n;
    int mod2 = 0, mod1 = 0;
    ll sum = 0;
    for (int i=0; i<n; ++i) {
        ll a; cin >> a;
        if (a % 3 == 2) ++mod2;
        else if (a % 3 == 1) ++mod1;
        sum += a;
    }

    if (sum % 3 == 0) return 0;
    else if (sum % 3 == 2) return 1;
    else if (sum % 3 == 1 and mod1) return 1;
    else if (sum % 3 == 1 and mod1==0 and mod2 > 1) return 2;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
}

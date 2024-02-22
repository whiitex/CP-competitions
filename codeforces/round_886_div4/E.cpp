#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef __int128_t lll;
typedef vector<ll> vll;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        ll n, c; cin >> n >> c;
        vll vec(n);
        for (int i=0; i<n; ++i) {
            ll a; cin >> a;
            c -= a*a;
            vec[i] = a;
        }
        c /= 4;

        ll l = 1, r = c;
        while (l < r) {
            lll w = (l+r+1) >> 1;
            lll ans = 0;
            for (ll v: vec) {
                ans += ((lll)v+w-1) * w;
                if (ans > (lll)c) break;
            }
            //lll fw = tot * w + (w-1)*n*w;
            if (ans > c)
                r = (ll)w - 1;
            else l = (ll)w;
        }

        cout << l << '\n';
    }
}

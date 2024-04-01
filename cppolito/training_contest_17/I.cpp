#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<ll> vll;

#define pb push_back
#define SIZE 64

ll powerlogn(ll b, ll exp) {
    ll mul = b;
    ll ans = 1;
    while (exp) {
        if (exp & 1) ans *= mul;
        mul *= mul;
        exp /= 2;
    }
    return ans;
}

vi binarize(ll n) { // 0 highest position
    vi ans;
    while (n) {
        ans.pb(ll(n & 1ll));
        n /= 2;
    }
    while (ans.size() < SIZE) ans.pb(0);
    std::reverse(ans.begin(), ans.end());
    return ans;
}


void solve() {
    ll n, m, i=0; cin >> n >> m;

    if ((n ^ m) < n) {
        cout << 1 << '\n';
        cout << n << ' ' << m << '\n';
        return;
    }

    vll ans {n};
    vi vn = binarize(n);
    vi vm = binarize(n);

    while (i<SIZE and not vn[i]) ++i; ++i;
    while (i<SIZE and (not vn[i] or (not vn[i] and vm[i]))) ++i;

    if (i == SIZE) {
        cout << -1 << '\n';
        return;
    }

    ll k = powerlogn(2, SIZE - i-1);
    for (; i<SIZE; ++i) {
        if (not vn[i])
            k += powerlogn(2, SIZE - i-1);
    }
    
    n = max(k, n ^ k);
    ans.pb(n);

    bool ok = true;
    if ((n ^ m) < n) {
        ans.pb(m);

    } else {
        vn = binarize(n);
        k = 0;
        for (ll j=0; j<SIZE; ++j) {
            if (vn[j] xor vm[j])
                k+= powerlogn(2, SIZE-j-1);
        }

        if (k < n and (k^n) < n) {
            ans.pb(m);
        } else ok = false;
    }
    

    if (ok) {
        cout << ans.size()-1 << '\n';
        for (ll q: ans) cout << q << ' ';
        cout << '\n';
    } else cout << -1 << '\n';

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t; cin >> t;
    while (t--) {
        solve();
    }
}

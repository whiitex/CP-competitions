#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

#define pb push_back
#define f first
#define s second

const ll MOD = 998244353;

ll fastexp(ll n, ll exp) {
    if (n == 1ll or n == 0) return 1ll;
    ll ans = 1, mul = n;
    while (exp) {
        if (exp & 1) ans = (ans * mul) % MOD;
        exp >>= 1;
        mul = (mul * mul) % MOD;
    }
    return ans;
}

void solve() {
    int n, m; cin >> n >> m;
    string s; cin >> s;
    --n;

    bool iszero = false;
    ll ans = 1;
    vll vec(n);
    for (ll i=n-1; i>0; --i) {
        if (s[i] == '<' or s[i] == '>')
            vec[i] = 1ll;
        else {
            vec[i] = i;
            ans = (ans * vec[i]) % MOD;
        }
    }

    if (s[0] == '?') iszero = true;

    if (iszero) cout << 0 << '\n';
    else cout << ans << '\n';

    while (m--) {
        ll ind; cin >> ind; --ind;
        char c; cin >> c;

        if (ind == 0 and c == '?') {
            cout << 0 << '\n';
            iszero = true;
            continue;
        }

        if (ind == 0 and c != '?') iszero = false;

        ans = (ans * fastexp(vec[ind], MOD-2)) % MOD;
        if (c == '?') {

            ans = (ans * max(ind, 1ll) ) % MOD;
            vec[ind] = ind;
        } else vec[ind] = 1;

        if (iszero) cout << 0 << '\n';
        else cout << ans << '\n';
    }

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t=1;
    while (t--) {
        solve();
    }
}

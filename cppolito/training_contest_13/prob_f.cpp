#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

const int MAX_N = 1e5 + 5;
const ll MOD = 998244353;


ll powlogn(ll b, ll exp) {
    ll mul = b;
    ll res = 1;
    while (exp) {
        if (exp & 1) res = (res * mul) % MOD;
        mul = (mul * mul) % MOD;
        exp /= 2;
    }
    return res % MOD;
}

void solve() {

    // init
    int n; cin >> n;
    vector<vector<int>> vec(n);
    vector<int> k(n);
    map<int,int> reg_kid;
    for (int i=0; i<n; ++i) {
        int ki; cin >> ki;
        k[i] = ki;
        vector<int> v(ki);
        for (int j=0; j<ki; ++j) {
            cin >> v[j];
            if (reg_kid.find(v[j]) != reg_kid.end()) ++reg_kid[v[j]];
            else reg_kid.insert({v[j], 1});
        }
        vec[i] = v;
    }

    // denominator
    ll totk = 0;
    for (auto val: k) totk += val;
    ll den = (totk * n) % MOD;
    den = powlogn(den, MOD-2) % MOD;

    // numerator
    ll num = 0;
    for (int i=0; i<n; ++i) {
        for (int present: vec[i]) {
            num += reg_kid[present];
            if (num > MOD) num %= MOD;
        }
    }

    ll res = (num * den) % MOD;
    cout << res;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t=1;
//    cin >> t;
    while (t--) {
        solve();
    }
}

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;


bool check(vector<ll> vec, int n, ll k) {
    set<ll> s;
    for (int i=0; i<n; ++i) {
        s.insert(vec[i] % k);
    }
    if (s.size() == 2) return true;
    return false;
}

void solve() {
    ll n; cin >> n;
    vector<ll> vec(n);
    for (int i=0; i<n; ++i) cin >> vec[i];

    ll k = 2;
    while (!check(vec, n, k)) k<<=1;
    cout << k << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

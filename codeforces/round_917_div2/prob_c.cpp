#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;


void solve() {
    ll n, k, d; cin >> n >> k >> d;
    vector<ll> a(n), b(k);
    for (int i=0; i<n; ++i) cin >> a[i];
    for (int i=0; i<k; ++i) cin >> b[i];
    ll ans = 0;

    // first zero
    int good=0;
    for(int i=0; i<n; ++i) {
        if (a[i] == i+1) ++good;
    }

    int newans=good, daysspent=1;
    for (int kk=0; kk<max(n,k); ++kk) {
        good = 0;
        for (int i=0; i<b[kk%k]; ++i) a[i]++;

        for (int i=0; i<n; ++i) if (a[i] == i+1) ++good;

        if (newans + (d-daysspent)/2 < (d-kk-2)/2 + good and d-kk-2>=0) {
            daysspent = kk+2;
            newans = good;
        }
    }

    ans = newans + (d-daysspent)/2;
    cout << ans << '\n';
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
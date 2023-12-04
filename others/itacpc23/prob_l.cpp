#include <bits/stdc++.h>

using namespace std;

#define lll __int128_t
#define ll long long
#define ld long double

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;


void solve() {

    // init
    int n; cin >> n;
    vector<pair<int,int>> vec(n);
    for (int i=0; i<n; ++i) {
        int a, b; cin >> a >> b;
        vec[i] = {b,a};
    }

    // sort and clean
    sort(vec.begin(), vec.end());
    for (int i=0; i<n-1; ++i)
        if (vec[i].first == vec[i+1].first) {
            vec[i].second = 0;
            vec[i + 1].second = 0;
        }

    // dp for best case
    vector<int> sol(n);
    int truesol = 0;
    sol[0] = vec[0].second;
    for (int i=1; i<n; ++i) {
        sol[i] = sol[i-1] + vec[i].second;
        truesol = max(truesol, sol[i]);
    }

    cout << truesol;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
}

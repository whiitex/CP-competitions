#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;


void solve() {
    ll n, total=0; cin >> n;
    vector<vector<ll>> vec(n);
    vector<ll> coord;
    for (int i=0; i<n; ++i) {
        int len; cin >> len;
        total += len;
        for (int j=0; j<len; j++) {
            ll el; cin >> el;
            coord.push_back(el);
            vec[i].push_back(el);
        }
    }

    // coordinate compression
    sort(coord.begin(), coord.end());
    map<ll, int> m;
    for (int i=0; i<total; ++i)
        m.insert({coord[i], i});

    for (int i=0; i<n; ++i) {
        for (int j=0; j<vec[i].size(); j++) {
            vec[i][j] = m[vec[i][j]];
        }
    }


    // splitting while not continuos
    ll s=0, c=0;
    for (int i=0; i<n; ++i) {
        for (int j=vec[i].size()-1; j>0; --j) {
            if (vec[i][j] != vec[i][j-1] + 1)
                ++s;
        }
    }

    c = n - 1 + s;
    cout << s << ' ' << c;


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

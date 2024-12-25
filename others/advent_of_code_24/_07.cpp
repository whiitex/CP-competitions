#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;

#define st first
#define nd second

bool f(vi& v, int exp) {
    if (v.size() == 1) return v[0] == exp;

    vi v1, v2, v3;
    v1.push_back(v[0] + v[1]);
    v2.push_back(v[0] * v[1]);
    v3.push_back((v[0] * (int)pow(10, to_string(v[1]).size())) + v[1]);
    for (int i = 2; i < (int)v.size(); i++) {
        v1.push_back(v[i]);
        v2.push_back(v[i]);
        v3.push_back(v[i]);
    }

    return f(v1, exp) or f(v2, exp) or f(v3, exp);
}

void solve() {
    vi exps = {3227574,9687,2594771266,9900354400,370759,6657,44100596,766963,19756163682741}; // ...
    int n = exps.size();
    vector<vi> vec = {
        {327,47,15,6,7,2},
        {6,72,7,3,615},
        {7,6,5,5,8,8,8,4,5,55,326,6},
        {8,75,9,9,2,5,451,6,8,50},
        {6,1,1,669,62},
        {91,54,22,981,8,82,741},
        // ...
    };

    int ans = 0;
    for (int i=0; i<n; ++i) {
        if (f(vec[i], exps[i])) ans += exps[i];
    }

    cout << ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();
}

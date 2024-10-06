#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
    int n, x; cin >> n >> x;
    vi vec(n); for (int &i: vec) cin >> i;

    // sort(vec.begin(), vec.end());
    // unordered_map<int,int> mp;
    //
    // int mex = 0, go = 1;
    // for (int i=0; i<n and go; ++i) {
    //     if (vec[i] == mex) { ++mex; continue; }
    //     if (vec[i] < mex) { ++mp[vec[i] % x]; continue; }
    //
    //     while (mex < vec[i] and mp[mex % x]) {
    //         --mp[mex % x];
    //         ++mex;
    //     }
    //
    //     if (mex == vec[i]) ++mex;
    //     else go = 0;
    // }
    //
    // while (mp[mex % x] and go) {
    //     --mp[mex % x];
    //     ++mex;
    // }

    int maxn = 2*n+3;
    vi cnt(maxn);
    for (int i: vec) if (i < maxn) ++cnt[i];
    for (int i=0; i<maxn; ++i) {
        if (i + x >= maxn) break;
        if (cnt[i]) cnt[i+x] += cnt[i] - 1;
    }

    int mex = 0;
    while (cnt[mex]) ++mex;

    cout << mex << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

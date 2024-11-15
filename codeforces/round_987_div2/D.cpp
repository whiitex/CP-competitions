#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

#define st first
#define nd second

const int INF = 1e18;

void solve() {
    int n; cin >> n;
    vi vec(n); for (int &i: vec) cin >> i;

    vpii pref(n); pref[0] = {vec[0], 0};
    for (int i=1; i<n; ++i) {
        if (vec[i] > pref[i-1].st) {
            pref[i] = {vec[i], i};
        } else pref[i] = pref[i-1];
    }

    vi ans(n);
    int j = n-1;
    while (j >= 0) {
        int poslx = pref[j].nd;

        int mn = INF;
        for (int i=poslx; i<=j; ++i) {
            mn = min(mn, vec[i]);
            ans[i] = vec[poslx];
        }

        int k = poslx-1;
        while (k >= 0 and pref[k].st > mn) {
            mn = min(mn, vec[k]);
            ans[k] = vec[poslx];
            --k;
        }

        j = k;
    }


    for (int i: ans) cout << i << ' ';
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

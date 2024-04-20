#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

string solve() {
    int n, k; cin >> n >> k;
    vi pref(n,0), vec(n,0);
    for (int i=n-k; i<n; ++i) cin >> pref[i];

    for (int i=n-1; i>=n-k+1; --i) {
        vec[i] = pref[i] - pref[i-1];
    }

    if (n == k) vec[0] = pref[0];
    else if (k == 1) vec[n-1] = max(pref[n-1], 0ll);
    else vec[n-k] = pref[n-k] > 0 ? min(pref[n-k], vec[n-k+1]) : vec[n-k+1];

    for (int i=n-k-1; i>=0; --i) {
        pref[i] = pref[i+1] - vec[i+1];
        if (i == 0) vec[0] = pref[0];
        else vec[i] = pref[i] > 0 ? min(pref[i], vec[i+1]) : vec[i+1];
    }

    for (int i=0; i<n-1; ++i)
        if (vec[i] > vec[i+1]) return "No";

    return "Yes";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) cout << solve() << '\n';
}

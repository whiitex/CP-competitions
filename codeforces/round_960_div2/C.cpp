#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

#define pb push_back

void solve() {
    int n; cin >> n;
    vi vec(n); for (int &i: vec) cin >> i;

    int ans = 0;
    unordered_map<int, int> mp;
    int mad = 0;
    vi a;
    for (int i=0; i<n; ++i) {
        ans += vec[i];
        ++mp[vec[i]];
        if (mp[vec[i]] > 1 and vec[i] > mad) mad = vec[i];
        a.pb(mad);
    }

    swap(a, vec);
    a = vi();
    mp = unordered_map<int,int>();
    mad = 0;
    for (int i=0; i<n; ++i) {
        ans += vec[i];
        ++mp[vec[i]];
        if (mp[vec[i]] > 1 and vec[i] > mad) mad = vec[i];
        a.pb(mad);
    }

    reverse(a.begin(), a.end());
    for (int i=0; i<a.size(); ) {
        int j = i+1, val = a[i];
        while (j < a.size() and a[j] == val) ++j;

        int len = j-i;
        ans += i * val * len;
        ans += len * (len+1) * val / 2;

        i = j;
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

#define pb push_back

void solve() {
    int n; cin >> n;
    vi vec(n); for (int &i: vec) cin >> i;

    sort(vec.begin(), vec.end());

    vi los;
    for (int i=0; i<n;) {
        int cnt = 0, val = vec[i];
        while (i < n and vec[i] == val) ++i, ++cnt;
        los.pb(cnt);
    }

    reverse(los.begin(), los.end());
    if (!los.empty()) for (int i: los) if (i & 1) {
        cout << "Yes\n"; return;
    }

    cout << "No\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

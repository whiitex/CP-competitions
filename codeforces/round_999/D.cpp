#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

#define pb push_back

void solve() {
    int n, m; cin >> n >> m;
    map<int,int> a;
    for (int i=0, x; i<n; ++i) {
        cin >> x; ++a[x];
    }
    vi b(m); for (int &i: b) cin >> i;

    int i = 0, rem = n;
    for (; i<(int)b.size(); ++i) {
        if ((int)b.size() - i > rem) break;

        if (a[b[i]]) --a[b[i]], --rem;
        else b.pb(b[i]/2), b.pb((b[i]+1)/2);
    }

    cout << (i == (int)b.size() and rem == 0 ? "Yes" : "No") << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

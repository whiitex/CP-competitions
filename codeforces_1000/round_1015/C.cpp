#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

#define pb push_back

void solve() {
    int n; cin >> n;
    vi a(n); for (int &i: a) cin >> i;
    vi b(n); for (int &i: b) cin >> i;

    int same = 0;
    vi posa(n+1); for (int i=0; i<n; ++i) posa[a[i]] = b[i];
    for (int i=0; i<n; ++i) {
        int posb = a[i];
        if (a[i] == b[i]) ++same;
        if (posa[b[i]] != posb) {cout << -1 << '\n'; return;}
    }

    if ((same != 1 and n & 1) or (same != 0 and (n % 2 == 0))) {
        cout << -1 << '\n'; return;
    }

    vpii ans;
    if (same == 1) {
        for (int i=0; i<n; ++i) if (a[i] == b[i]) {
            if (i+1 != n/2 + 1) {
                ans.pb({i+1, n/2 + 1});
                swap(a[i], a[n/2]);
                swap(b[i], b[n/2]);
                break;
            }
        }
    }

    vi posb(n+1); for (int i=0; i<n; ++i) posb[b[i]] = i;
    for (int i=0; i<n/2; ++i) {
        int x = a[i];
        if (posb[x] != n-i-1) {
            ans.pb({n-i, posb[x] + 1});
            swap(a[n-i-1], a[posb[x]]);
            swap(b[n-i-1], b[posb[x]]);
            posb[b[posb[x]]] = posb[x];
            posb[b[n-i-1]] = n-i-1;
        }
    }

    cout << ans.size() << '\n';
    for (auto [x, y]: ans) {
        cout << x << ' ' << y << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

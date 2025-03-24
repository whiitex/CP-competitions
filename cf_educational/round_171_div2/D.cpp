#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;

#define pb push_back
#define st first
#define nd second

void solve() {
    int n; cin >> n;
    vi vec(n); for (int &i: vec) cin >> i;

    vi pref(vec); for (int i=1; i<n; ++i) pref[i] += pref[i-1];
    vi span = {n}; for (int i=1; i<n; ++i) span.pb(span.back() + (n-i));

    vi tott(vec); for (int i=n-2; i>=0; --i) tott[i] = vec[i] * (n-i) + tott[i+1];
    vi preftot(tott); for (int i=1; i<n; ++i) preftot[i] += preftot[i-1];

    vi tot(vec); for (int i=n-2; i>=0; --i) tot[i] = vec[i] * (n-i);
    vi invpreftot(tot); for (int i=n-2; i>=0; --i) invpreftot[i] += invpreftot[i+1];
    invpreftot.pb(0);

    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;

        pii A;
        A.st = lower_bound(span.begin(), span.end(),  l) - span.begin();
        A.nd = A.st == 0 ? l-1 : A.st + l-1 - span[A.st-1];

        pii B;
        B.st = lower_bound(span.begin(), span.end(),  r) - span.begin();
        B.nd = B.st == 0 ? r-1 : B.st + r-1 - span[B.st-1];

        int ans = preftot[B.st] - preftot[A.st];

        int com = pref[A.nd] - (A.st > 0 ? pref[A.st-1] : 0);
        ans += com * (n-A.nd);

        ans += invpreftot[A.nd+1];

        com = pref[B.nd] - (B.st > 0 ? pref[B.st-1] : 0);
        ans -= com * (n-1-B.nd);

        ans -= invpreftot[B.nd+1];

        cout << ans << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; // cin >> t;
    while (t--) solve();
}

#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

#define pb push_back

void solve() {
    int n, k; cin >> n >> k;
    vi a(n); for (int &i: a) cin >> i;
    vi b(n); for (int &i: b) cin >> i;
    vi all; for (int i: a) all.pb(i); for (int i: b) all.pb(i);

    vi A(a); for (int &i: A) i = -i;
    vi B(b); for (int &i: B) i = -i;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int ans = 0;
    for (int i: all) {

        int pos = upper_bound(A.begin(), A.end(), -i) - A.begin();
        int neg = upper_bound(B.begin(), B.end(), -i) - B.begin();

        neg -= pos;
        if (neg <= k) ans = max(ans, i * (pos+neg));
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;

#define pb push_back

const int INF = 1e18;

void solve() {
    int n; cin >> n;
    vi a(n); for (int &i: a) cin >> i;

    int ans = 0, zeros = 0;
    for (int i: a) {
        ans += i != 0;
        zeros += i == 0;
    }

    if (zeros) {
        vi A; int zer = 1;
        for (int i=0; i<n; ++i) {
            if (a[i] != 0) A.pb(a[i]);
            if (a[i] == 0 and zer) A.pb(0), zer = 0;
        }
        int N = (int)A.size();

        // check
        set<int> mex; int mn = INF, ok = 1;
        vi f(n+10); for (int i=0; i<N; ++i) if (A[i] < n+10) ++f[A[i]];
        for (int i=0; i<n+10; ++i) if (!f[i]) mex.insert(i);

        for (int i=0; i<N-1; ++i) {
            mn = min(mn, A[i]);
            if (A[i] < n+10) {
                --f[A[i]];
                if (!f[A[i]]) mex.insert(A[i]);
            }
            if (mn < *mex.begin()) ok = 0;
        }

        if (ok) ++ans;
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

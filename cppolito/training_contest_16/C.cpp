#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vpii;

#define pb push_back
#define f first
#define s second

void solve() {
    int n, m; cin >> n >> m;

    if (m < n-1) {
        cout << "Impossible" << '\n';
        return;
    }

    vector<pii> ans;
    for (int i=2; i<=n and m; ++i)
        ans.pb({1, i});
    m -= n - 1;

    for (int val=2; val <= n and m; ++val) {

        for (int i=val+1; i <= n and m; ++i) {
            if (__gcd(val, i) == 1) {
                ans.pb({val, i});
                --m;
            }
        }
    }

    if (m)
        cout << "Impossible\n";
    else {
        cout << "Possible\n";
        for (pii p: ans) cout << p.f << ' ' << p.s << '\n';
    }

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}

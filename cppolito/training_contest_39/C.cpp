#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

#define pb push_back
#define st first
#define nd second

void solve() {
    int n; cin >> n;
    vpii a(n); for (auto &p: a) cin >> p.st >> p.nd;

    vi o(n); iota(o.begin(), o.end(), 0);
    sort(o.begin(), o.end(), [&] (int x, int y) -> bool {
        if (a[x].nd == a[y].nd) return a[x].st < a[y].st;
        return a[x].nd < a[y].nd;
    });

    vi ans(n), used(1e7+10, 0);
    for (int i=0; i<n; ++i) {
        int j = a[o[i]].st;
        while (used[j]) ++j;

        ans[o[i]] = used[j] = j;
    }

    for (int i: ans) cout << i << ' ';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();
}

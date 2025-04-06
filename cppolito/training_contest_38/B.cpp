#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

#define f first
#define s second

const int INF = 1e18;

void solve() {
    int n; cin >> n;
    vi vec(n); for (int &i: vec) cin >> i;

    vpii pos(n+1, {INF, 0});
    for (int i=0; i<n; ++i) {
        pos[vec[i]].f = min(pos[vec[i]].f, i);
        pos[vec[i]].s = max(pos[vec[i]].s, i);
    }

    int ll = -1, lr = -1, L, R, bonus;
    for (int i=1; i<=n; ++i) if (pos[i].f != INF) {
        int l = pos[i].f, r = pos[i].s;

        if (ll == -1) { // first cycle
            ll = L = l; lr = r;

            int width = lr - ll + 1;
            if (width > i) { cout << 0 << '\n'; return; }
            bonus = i - width;
        } else { // next cycles
            if (l > ll and r < lr) continue;

            int width = max(lr, r) - min(ll, l) + 1;
            if (width > i) { cout << 0 << '\n'; return; }

            ll = min(ll, l); lr = max(lr, r);
            int diff = min(bonus, L - ll);
            L -= diff;
            bonus = min(bonus - diff, i - width);
        }
    }

    ll = -1, lr = -1;
    for (int i=1; i<=n; ++i) if (pos[i].f != INF) {
        int l = pos[i].f, r = pos[i].s;

        if (ll == -1) { // first cycle
            ll = l; lr = R = r;

            int width = lr - ll + 1;
            if (width > i) { cout << 0 << '\n'; return; }
            bonus = i - width;
        } else { // next cycles
            if (l > ll and r < lr) continue;

            int width = max(lr, r) - min(ll, l) + 1;
            if (width > i) { cout << 0 << '\n'; return; }

            ll = min(ll, l); lr = max(lr, r);
            int diff = min(bonus, lr - R);
            R += diff;
            bonus = min(bonus - diff, i - width);
        }
    }

    cout << min(n, R - L + 1) << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}
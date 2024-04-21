#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
    int n; cin >> n;
    vi p(n); for (int &i: p) cin >> i;
    vi q(n); for (int &i: q) cin >> i;

    if (n == 1) {
        cout << 1 << '\n'; return;
    }

    vi posp(n+1), posq(n+1);
    for (int i=0; i<n; ++i) {
        posp[p[i]] = i;
        posq[q[i]] = i;
    }

    int lp = posp[1], rp = posp[1];
    int lq = posq[1], rq = posq[1];
    int ans = 0;
    int d = min(lp, lq);
    ans +=  d * (d+1) /2;
    d = n - max(rp, rq) -1;
    ans +=  d * (d+1) /2;
    d = abs (lp - lq) - 1;
    ans +=  d * (d+1) /2;

    int l;

    for (int i=2; i<n; ++i) {
        bool add = true;
        if (i == 2) {
            if (posp[2] >= min(lp, lq) and posp[2] <= max(lp, lq)) add = false;
            if (posq[2] >= min(lp, lq) and posq[2] <= max(lp, lq)) add = false;

            if (min(posp[2], posq[2]) < min(lp, lq) and max(posp[2], posq[2]) > max(lp, lq)) {
                d = max(posp[2], posq[2]) - max(lp, lq);
                l = min(lp, lq) - min(posp[2], posq[2]);
            } else if (max(posp[2], posp[2]) < min(lp, lq)) {
                d = n - max(lp, lq);
                l = min(lp, lq) - max(posp[2], posq[2]);
            } else {
                d = min(lp, lq) + 1;
                l = min(posp[2], posq[2]) - max(lp, lq);
            }

            if (add) ans += d * l;

            lp = min(lp, posp[2]);
            rp = max(rp, posp[2]);
            lq = min(lq, posq[2]);
            rq = max(rq, posq[2]);
            continue;
        }

        int lx = min (lp, lq);
        int rx = max (rp, rq);
        if (posp[i] >= lx and posp[i] <= rx) add = false;
        if (posq[i] >= lx and posq[i] <= rx) add = false;

        if (lx > max(posp[i], posq[i])) {
            d = n - rx;
            l = lx - max(posp[i], posq[i]);
        } else if (rx < min(posp[i], posq[i])) {
            d = lx + 1;
            l = min(posp[i], posq[i]) - rx;
        } else {
            d = max(posp[i], posq[i]) - rx;
            l = lx - min(posp[i], posq[i]);
        }

        if (add) ans += d * l;

        lp = min(lp, posp[i]);
        rp = max(rp, posp[i]);
        lq = min(lq, posq[i]);
        rq = max(rq, posq[i]);
    }

    cout << ans+1 << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t=1;// cin >> t;
    while (t--) solve();
}

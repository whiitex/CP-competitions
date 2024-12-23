#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

#define pb push_back

void solve() {
    int n, m, q; cin >> n >> m >> q;

    int tot = 1;
    set<int> mid, lx, rx;
    if (m > 1 and m < n) mid.insert(m);
    if (m == 1) lx.insert(1);
    if (m == n) rx.insert(n);

    while (q--) {
        int a; cin >> a;
        if (tot == n) { cout << n << ' '; continue;}

        if (mid.contains(a) and tot == 1) {
            mid.erase(a); lx.insert(1); rx.insert(n);
            tot = 2;
        } else if (tot == 1 and lx.contains(a)) {
            ++tot; rx.insert(n);
        } else if (tot == 1 and rx.contains(a)) {
            ++tot; lx.insert(1);
        } else if (tot < n) {

            vi inr, inmid, inl;
            if (!lx.empty() and a > *lx.rbegin()) {
                int ins = *lx.rbegin() + 1;
                if (!rx.contains(ins) and !lx.contains(ins) and !mid.contains(ins)) ++tot;
                lx.insert(ins);
            } else if (!lx.empty() and lx.contains(a)) {
                if (!rx.contains(n) and !mid.contains(n) and !lx.contains(n)) ++tot;
                inr.pb(n);
            }


            if (!rx.empty() and a < *rx.begin()) {
                int ins = *rx.begin() - 1;
                if (!rx.contains(ins) and !lx.contains(ins) and !mid.contains(ins)) ++tot;
                rx.insert(ins);
            } else if (!rx.empty() and rx.contains(a)) {
                if (!lx.contains(1) and !mid.contains(1) and !rx.contains(1)) ++tot;
                lx.insert(1);
            }

            if (!mid.empty() and mid.contains(a)) {
                if (!lx.contains(1) and !mid.contains(1) and !rx.contains(1)) ++tot;
                if (!rx.contains(n) and !mid.contains(n) and !lx.contains(n)) ++tot;
                inl.pb(1); inr.pb(n);
            }

            if (!mid.empty() and a < *mid.begin()) {
                int ins = *mid.begin() - 1;
                if (!rx.contains(ins) and !lx.contains(ins) and !mid.contains(ins)) ++tot;
                inmid.pb(ins);
            }
            if (!mid.empty() and a > *mid.rbegin()) {
                int ins = *mid.rbegin() + 1;
                if (!rx.contains(ins) and !lx.contains(ins) and !mid.contains(ins)) ++tot;
                inmid.pb(ins);
            }

            for (int i: inr) rx.insert(i);
            for (int i: inl) lx.insert(i);
            for (int i: inmid) mid.insert(i);

        }

        cout << tot << ' ';
    }  cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

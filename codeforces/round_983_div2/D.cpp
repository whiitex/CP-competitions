#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

#define pb push_back

int ask(int x, int y) {
    cout << "? " << x << ' ' << y << endl;
    int a; cin >> a; return a;
}

void solve() {
    int n; cin >> n;

    set<int> st;
    vi par(n); par[1] = 0;

    int x=2; while (ask(1, x)) ++x;

    par[x] = 1; st.insert(x);
    for (int i=2; i<x; ++i) {
        par[i] = 0;
        st.insert(i);
    }

    ++x;
    vi to_erase;
    while (x < n) {
        for (int i: st) {
            to_erase.pb(i);
            if (ask(i, x) == 0) {
                par[x] = i;
                st.insert(x);
                break;
            }
        }

        for (int i: to_erase) st.erase(i);
        to_erase.clear();
        ++x;
    }


    cout << "! ";
    for (int i=1; i<n; ++i) cout << par[i] << ' ';
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

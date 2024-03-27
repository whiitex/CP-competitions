#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

void ask (int a, int b, int c, int d) {
    cout << "? " << a << ' ' << b << ' ' << c << ' ' << d << '\n';
    cout.flush();
}

void solve() {
    int n; cin >> n;
    char resp;
    vi vec(n); for (int i=0; i<n; ++i) vec[i] = i;
    if (n == 2) {
        cout << "! 0 1\n";
        cout.flush();
        return;
    }

    int mx=0;
    for (int i=1; i<n; ++i) {
        ask(mx, mx, i, i);
        cin >> resp;
        if (resp == '<') mx = i;
    }

    int sec = 0;
    set<int> st = {0};
    for (int i=1; i<n; ++i) {
        ask(mx, sec, mx, i);
        cin >> resp;
        if (resp == '<') {
            sec = i;
            st.clear();
            st.insert(sec);
        } else if (resp == '=')
            st.insert(i);
    }

    int mn = *st.begin();
    for (int i: st) {
        ask(mn, mn, i, i);
        cin >> resp;
        if (resp == '>') mn = i;
    }

    cout << "! " << mx << ' ' << mn << '\n';
    cout.flush();

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}

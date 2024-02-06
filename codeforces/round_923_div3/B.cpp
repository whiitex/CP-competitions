#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

void solve() {
    int n; cin >> n;
    vi vec(n); for (int& i: vec) cin >> i;
    vi ch(30,0);
    vector<char> s(n);

    for (int i=0; i<n; ++i) {
        int j=0;
        while(ch[j] != vec[i] and j<30) ++j;
        ++ch[j];
        s[i] = j + 'a';
    }

    for (char c: s)
        cout << c;
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}

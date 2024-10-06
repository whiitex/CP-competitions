#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
    int n, m, q; cin >> n >> m >> q;
    vi a(n); for (int &i: a) cin >> i;
    vi b(m); for (int &i: b) cin >> i;

    set<int> st;
    int j=0;
    for (int i: b) {
        if (j == n) break;
        if (!st.empty() and st.contains(i)) continue;
        if (a[j] == i) {
            st.insert(i); ++j;
            continue;
        }
        cout << "Tidak\n"; return;
    }

    cout << "Ya\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

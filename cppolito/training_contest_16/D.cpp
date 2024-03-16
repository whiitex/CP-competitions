#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

void solve() {
    int m, n; cin >> m >> n;

    vi p(n);
    for (int i=0; i<n; ++i) {
        cout << 1 << endl;
        cin >> p[i];
        if (p[i] == 0) return;
    }

    int l = 2, r = m, i = 0, resp;
    while (l < r) {
        int mid = l+r >> 1;
        cout << mid << endl;
        cin >> resp;

        if (resp == 0) return;

        if (p[i%n] * resp == 1)
            l = mid + 1;
        else if (p[i%n] * resp == -1)
            r = mid;
        ++i;
    }

    cout << l << endl;
    cin >> resp;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

#define pb push_back

void solve() {
    int n, k; cin >> n >> k;

    vi assign(n);
    int Ass = 1;

    for (int i=0; i<n;) {

        int ass = min(Ass + k/2-1, Ass + ((n-Ass)/2));
        int delta = ass - Ass;
        int d = i;
        while (ass >= Ass) {
            assign[d] = ass--;
            ++d;
        }

        ass = min(Ass + k - 1, n);
        for (int d=i+delta+1; d < min(i+k, n); ++d)
            assign[d] = ass--;

        Ass += k;
        i += k;
    }

    for (int i: assign) cout << i << ' '; cout << '\n';
    cout << ((n + k - 1) / k) << '\n';

    int cl = 1;
    for (int i=0; i<n;) {
        for (int d=i; d < min(i+k, n); ++d) {
            cout << cl << ' ';
        }
        ++cl;
        i += k;
    }
    cout << '\n';

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}

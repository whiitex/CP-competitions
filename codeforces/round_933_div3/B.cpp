#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

void solve() {
    int n; cin >> n;
    vi vec(n); for (int &i: vec) cin >> i;

    int last = n-2;
    for (int i = 1; i<=last;) {

        if (i == last) {
            if (vec[i] == 2*vec[i-1] and vec[i] == 2*vec[i+1]) {
                cout << "Yes\n";
                return;
            } else {
                cout << "No\n";
                return;
            }
        }

        if (vec[i] == 0 and vec[i-1] == 0) {
            ++i; continue;
        }

        if (vec[i] == 0 and vec[i-1]) {
            cout << "No\n";
            return;
        }
        if (vec[i] - 2*vec[i-1] >= 0 and vec[i+1] >= vec[i-1]) {
            vec[i] -= 2 * vec[i-1];
            vec[i+1] -= vec[i-1];
            ++i;
        } else {

            if (vec[last] == 0 and vec[last+1] == 0) {
                --last;
                continue;
            }

            if (vec[last] == 0 and vec[last+1]) {
                cout << "No\n";
                return;
            }
            if (vec[last] - 2 * vec[last + 1] >= 0 and vec[last - 1] >= vec[last + 1]) {
                vec[last] -= 2 * vec[last + 1];
                vec[last-1] -= vec[last + 1];
                --last;
            } else {
                cout << "No\n";
                return;
            }
        }

    }

    cout << "Yes\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}

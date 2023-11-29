#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i<n; i++)
        cin >> arr[i];

    if (k != 4) {
        int m = 10;
        bool ok = false;
        for (int i = 0; i < n; i++) {
            if (arr[i] % k == 0) {
                cout << 0 << '\n';
                ok = true;
                break;
            }
            int t = k - (arr[i] % k);
            if (t < m) m = t;
        }
        if (!ok) cout << m << '\n';

        // k == 4
    } else {
        int three = 0, two = 0, one = 0;
        bool ok = false;

        for (int i = 0; i<n; i++) {
            if (arr[i] % 4 == 0) {
                cout << 0 << '\n';
                ok = true;
                break;
            }
            if (arr[i] % 4 == 1) one++;
            if (arr[i] % 4 == 2) two++;
            if (arr[i] % 4 == 3) three++;
        }

        if (!ok) {
            if (two > 1) cout << 0 << '\n';
            else if (three > 0 || (two%2==1 && one>0) ) cout << 1 << '\n';
            else if (two == 0 && three == 0 && one == 1) cout << 3 << '\n';
            else cout << 2 << '\n';
        }


    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

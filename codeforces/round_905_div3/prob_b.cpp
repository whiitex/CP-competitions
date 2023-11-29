#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, kk;
    cin >> n >> kk;
    string s;
    cin >> s;

    int k = kk;
    if (kk == n || kk == n-1) {
        cout << "YES" << '\n';
    } else {

        for (int i = 0; i<n; i++) {
            if (s[i] != '*') {

                bool found = false;
                for (int j = i + 1; j < n; j++) {
                    if (s[i] == s[j]) {
                        found = true;
                        s[j] = '*';
                        break;
                    }
                }
                if (!found) k--;
            }
        }

        if (k == -1 && (n-kk) % 2 == 1)
            cout << "YES" << '\n';
        else if ( k>0 && k%2 == 1 && (n-kk)%2 == 1)
            cout << "YES" << '\n';
        else if ( k>=0 && k%2 == 0)
            cout << "YES" << '\n';
        else cout << "NO" << '\n';
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

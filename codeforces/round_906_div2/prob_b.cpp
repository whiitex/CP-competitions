#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){

    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s;
    cin >> t;


    bool issgood = true;
    for (int i=0; i<n-1; i++)
        if (s[i] == s[i+1]) {
            issgood = false;
            break;
        }

    if (issgood) cout << "YES" << '\n';
    else {

        bool istgood = true;
        for (int i = 0; i < m-1; i++)
            if (t[i] == t[i + 1]) {
                istgood = false;
                break;
            }


        char first_t;
        if (t[0] == t[m - 1])
            first_t = t[0];
        else istgood = false;

        if (istgood) {

            bool p = true;
            for (int i = 0; i < n - 1; i++) {
                if (s[i] == s[i + 1]) {
                    if (s[i] == first_t) {
                        p = false;
                        break;
                    }
                }
            }

            if (p) cout << "YES" << '\n';
            else cout << "NO" << '\n';

        } else
            cout << "NO" << '\n';
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

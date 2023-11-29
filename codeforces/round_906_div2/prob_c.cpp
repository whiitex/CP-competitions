#include <bits/stdc++.h>
#define ll long long

using namespace std;

bool check(string s, int n) {
    for (int i=0; i<n/2; i++) {
        if (s[i] == s[n-i-1])
            return false;
    }
    return true;
}

void solve() {

    int n;
    string s;
    cin >> n;
    cin >> s;

    if (check(s, n) && n%2==0) {
        cout << 0 << '\n';
        cout << '\n';
    } else if (n%2==1) {
        cout << -1 << '\n';
    } else {

        int op = 0, mid = n/2, i=0;
        vector<int> ops;
        while (op<=300 && i<mid) {

            if (s[i] == s[n-i-1] && s[i] == '1') {
                s = s.substr(0,i) + "01" + s.substr(i, n-i);
                ops.push_back(i);
                op ++;
                mid++;
                n += 2;
                i++;
            }
            else if (s[i] == s[n-i-1] && s[i] == '0') {
                s = s.substr(0,n-i) + "01" + s.substr(n-i, i);
                ops.push_back(n-i);
                op ++;
                mid++;
                n += 2;
                i++;
            }
            else i++;

        }

        if (op <= 300) {
            cout << op << '\n';
            for (int x : ops)
                cout << x << ' ';
            cout << '\n';
        } else cout << -1 << '\n';




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

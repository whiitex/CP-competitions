#include <bits/stdc++.h>

using namespace std;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        string a, b; cin >> a >> b;
        if (a == b) cout << "=\n";
        else {
            char enda = *a.rbegin();
            char endb = *b.rbegin();

            if (enda == endb and enda == 'S')
                cout << (a.length() > b.length() ? '<' : '>') << '\n';
            else if (enda == endb and enda == 'L')
                cout << (a.length() < b.length() ? '<' : '>') << '\n';
            else if (enda == 'S')
                cout << '<' << '\n';
            else if (enda == 'L')
                cout << '>' << '\n';
            else {
                if (endb == 'S') cout << '>' << '\n';
                else cout << '<' << '\n';
            }
        }
    }
}

#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {

        for (int i=0; i<3; ++i) {
            string s; cin >> s;
            int a=0, b=0, c=0;
            for (char ch: s) {
                if (ch == 'A') ++a;
                if (ch == 'B') ++b;
                if (ch == 'C') ++c;
            }
            if (a + b + c < 3) {
                if (not a) cout << 'A' << '\n';
                if (not b) cout << 'B' << '\n';
                if (not c) cout << 'C' << '\n';
            }
        }

    }
}

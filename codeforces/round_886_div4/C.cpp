#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        string s;
        int index = -1;
        for (int i=0; i<8; ++i) {
            string row; cin >> row;
            if (std::count(row.begin(), row.end(),'.') == 8) continue;

            if (index == -1) {
                for (int i=0; i<8; ++i)
                    if (row[i] != '.') {
                        index = i;
                        break;
                    }
            }

            if (index >= 0 and row[index] != '.')
                s.push_back(row[index]);
        }

        cout << s << '\n';
    }
}

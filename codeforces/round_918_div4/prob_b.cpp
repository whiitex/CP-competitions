#include <bits/stdc++.h>

using namespace std;

#define lll __int128_t
#define ll long long
#define ld long double

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;


void solve() {
    string mat[3];
    int row;
    for (int i=0; i<3; ++i) {
        cin >> mat[i];
        for (int k=0; k<3; ++k)
            if (mat[i][k] == '?') {
                row = i;
            }
    }

    bool a=true, b=true, c=true;
    for(int i=0; i<3; ++i) {
        if (mat[row][i] == 'A') a = false;
        if (mat[row][i] == 'B') b = false;
        if (mat[row][i] == 'C') c = false;
    }

    if (a) cout << "A\n";
    if (b) cout << "B\n";
    if (c) cout << "C\n";


}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

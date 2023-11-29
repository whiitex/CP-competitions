#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m;
    string x, y;
    cin >> n >> m;
    cin >> x >> y;

    int num_of_op = 0;
    bool ok = true;
    int flag = 0;

    while(num_of_op < 10 && ok) {
        flag = x.find(y);
        if (flag >= 0) {
            cout << num_of_op << '\n';
            ok = false;
        } else {
            num_of_op++;
            x = x + x;
        }
    }

    if (ok) cout << -1 << '\n';


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


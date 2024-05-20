#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;

#define pb push_back

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vi pos(4,0);
    for (char c: s) {
        if (c == 'N') ++pos[0];
        if (c == 'S') ++pos[1];
        if (c == 'E') ++pos[2];
        if (c == 'W') ++pos[3];
    }

    vi r(4,0), h(4,0);
    bool ns = false;
    if (pos[0] % 2 == 0 and pos[1] % 2 == 0) {
        r[0] += pos[0] / 2;
        h[0] += pos[0] / 2;
        r[1] += pos[1] / 2;
        h[1] += pos[1] / 2;
        ns = true;
    } else if (pos[0] % 2 == 1 and pos[1] % 2 == 1) {
        --pos[0]; --pos[1];
        r[0] += pos[0] / 2+1;
        h[0] += pos[0] / 2;
        r[1] += pos[1] / 2+1;
        h[1] += pos[1] / 2;
        ns = true;
    }

    bool we = false;
    if (pos[2] % 2 == 0 and pos[3] % 2 == 0) {
        h[2] += pos[2] / 2;
        r[2] += pos[2] / 2;
        r[3] += pos[3] / 2;
        h[3] += pos[3] / 2;
        we = true;
    } else if (pos[2] % 2 == 1 and pos[3] % 2 == 1) {
        --pos[0]; --pos[1];
        r[2] += pos[2] / 2;
        h[2] += pos[2] / 2+1;
        r[3] += pos[3] / 2;
        h[3] += pos[3] / 2+1;
        we = true;
    }

    if (we and ns) {
        string ans;
        for (char c: s) {
            int ind;
            if (c == 'N') ind = 0;
            if (c == 'S') ind = 1;
            if (c == 'E') ind = 2;
            if (c == 'W') ind = 3;
            if (r[ind]) {
                ans.pb('R'); --r[ind];
            } else {
                ans.pb('H');
            }
        }

        int ctR = std::count(ans.begin(), ans.end(), 'R');
        if (ctR == n or ctR == 0)
            cout << "NO" << '\n';
        else cout << ans << '\n';
    } else cout << "NO" << '\n';

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}

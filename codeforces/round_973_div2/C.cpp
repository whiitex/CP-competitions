#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

#define pb push_back

int ask(string t, string u) {
    cout << "? " << t << u << endl;
    int a; cin >> a; return a;
}

void answer(string t, string u) {
    cout << "! " << t << u << endl;
}

void solve() {
    int n; cin >> n;

    string t, u;
    bool go = true;
    for (int i=0; i<n; ++i) {

        if (go) {
            u.pb('0');
            int check = ask(t, u);
            if (check == 1) continue;

            u.pop_back();
            u.push_back('1');
            check = ask(t, u);
            if (check == 0) {
                go = false;
                u.pop_back();
                --i;
            }
        } else {
            reverse(t.begin(), t.end());
            t.push_back('0');
            reverse(t.begin(), t.end());
            int check = ask(t, u);
            if (check == 1) continue;

            reverse(t.begin(), t.end());
            t.pop_back();
            t.push_back('1');
            reverse(t.begin(), t.end());
        }
    }

    answer(t, u);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

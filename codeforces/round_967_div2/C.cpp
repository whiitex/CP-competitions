#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef pair<int,int> pii;
typedef vector<pii> vpii;

#define pb push_back
#define f first
#define s second

int ask(int a, int b) {
    cout << "? " << a << ' ' << b << endl;
    int c; cin >> c; return c;
}

void solve() {
    int n; cin >> n;

    vpii ans;
    for (int i=2; i<=n; ++i) {
        int a, b = i, c = 1;
        do {
            a = c;
            c = ask(a, b);
        } while (c != a and c != b);

        if (c == a) ans.pb({a, b});
        else if (b == c) ans.pb({a, b});
    }

    cout << "! ";
    for (pii p: ans) cout << p.f << ' ' << p.s << ' ';
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

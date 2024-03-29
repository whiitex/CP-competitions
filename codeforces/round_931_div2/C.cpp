#include <bits/stdc++.h>

using namespace std;

void ask(int x, int y) {
    cout << "? " << x << ' ' << y << '\n';
    cout.flush();
}

void answer(int x, int y) {
    cout << "! " << x << ' ' << y << '\n';
    cout.flush();
}

void solve() {
    int n, m, resp; cin >> n >> m;
    int a, b, c;

    ask(1,1);
    cin >> a; ++a;
    int A = a;
    // x = A - y + 1
    // y = A - x + 1

    ask(n, m);
    cin >> b; ++b;
    int B = n + m - b;
    // x = B - y + 1
    // y = B - x + 1

    ask(1, m);
    cin >> c; ++c;
    int C = c - m + 1;
    // x = C + y - 1
    // y = x - C + 1

    if ((a+ n%2==0) % 2 == c % 2 and (b + m%2==0) % 2 != c % 2)
        // A - y + 1 = C + y - 1
        // y = (A-C+2)/2
        // A - x + 1 = x - C + 1
        // x = (A+C)/2
        answer((A+C)/2, (A-C+2)/2);

    else if ( (a+ n%2==0) % 2 != c % 2 and (b + m%2==0) % 2 == c % 2)
        answer((B+C)/2, (B-C+2)/2);
    else {
        int x1 = (A+C)/2, y1 = (A-C+2)/2;
        if (x1 > 0 and x1 <=n and y1 > 0 and y1 <= m) {
            ask(x1, y1);
            int k;
            cin >> k;
            if (k == 0) answer(x1, y1);
            else answer((B + C) / 2, (B - C + 2) / 2);
        } else answer((B + C) / 2, (B - C + 2) / 2);
    }

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}

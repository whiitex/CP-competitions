#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;

#define f first
#define s second

void solve() {
    int a, b, n, m; cin >> a >> b >> n >> m;
    pii A = {1,1},  B = {a, b};

    set<pii> row, col;
    for (int i=0; i<n; ++i) {
        pii p; cin >> p.f >> p.s;
        row.insert(p);
        col.insert({p.s, p.f});
    }

    int alice = 0, bob = 0;
    bool isAl = 1;
    for (int _=0; _<m; _++) {
        char c; cin >> c;
        int num; cin >> num;
        int toadd = 0;

        if (c == 'U') {
            while (!row.empty() and (*row.begin()).f < A.f + num) {
                ++toadd;
                auto p = *row.begin();
                row.erase(p);
                col.erase({p.s, p.f});
            }
            A.f += num;
        }

        else if (c == 'D') {
            while (!row.empty() and (*row.rbegin()).f > B.f - num) {
                ++toadd;
                auto p = *row.rbegin();
                row.erase(p);
                col.erase({p.s, p.f});
            }
            B.f -= num;
        }

        else if (c == 'L') {
            while (!col.empty() and (*col.begin()).f < A.s + num) {
                ++toadd;
                auto p = *col.begin();
                col.erase(p);
                row.erase({p.s, p.f});
            }
            A.s += num;
        }

        else if (c == 'R') {
            while (!col.empty() and (*col.rbegin()).f > B.s - num) {
                ++toadd;
                auto p = *col.rbegin();
                col.erase(p);
                row.erase({p.s, p.f});
            }
            B.s -= num;
        }

        if (isAl) alice += toadd;
        else bob += toadd;
        isAl ^= 1;
    }

    cout << alice << ' ' << bob << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}

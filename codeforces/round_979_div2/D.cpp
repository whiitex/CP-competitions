#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

#define f first
#define s second

void solve() {
    int n, q; cin >> n >> q;
    vi vec(n); for (int &i: vec) cin >> i;
    string yes = "YES", no = "NO";
    string s; cin >> s;

    int x = 1; vpii ck(n);
    for (int i=0; i<n; ++i) {
        if (vec[i] == x) {
            ck[i] = {x, x};
            continue;
        }

        int mx = vec[i], j = i+1;
        while (j < mx) {
            mx = max(mx, vec[j]);
            ++j;
        }

        for (int k=i; k<j; ++k) {
            ck[k] = {i+1, j};
        }

        i = j-1; x = j;
    }

    set<int> wrong;
    for (int i=1; i<n; ++i) wrong.insert(i);
    for (int i=0; i<n; ++i) {
        auto [a, b] = ck[i];
        if (a == b) wrong.erase(i+1);
        if (b == i+1) wrong.erase(b);
        if (a == i+1) wrong.erase(a-1);
    }
    for (int i=0; i<n; ++i) {
        if (s[i] == 'L') {
            wrong.erase(i);
        } else if (s[i] == 'R') {
            wrong.erase(i+1);
        }
    }

    while (q--) {
        int a; cin >> a;
        char nw = s[a-1] == 'L' ? 'R' : 'L';
        s[a-1] = nw;

        if (nw == 'R') {
            wrong.erase(a);
            if (ck[a-1].f < a and s[a-2] == 'L')
                wrong.insert(a-1);
        } else { // L
            wrong.erase(a-1);
            if (ck[a-1].s > a and s[a] == 'R')
                wrong.insert(a);
        }

        // output
        if (wrong.empty()) cout << "YES\n";
        else cout << "NO\n";
    }

}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}
/*
1 5 5
2 4 3 1 5
RRLLL 3 2 4 3 4

1 3 5
1 2 3
RRL 2 2 2 2 2

1 6 3
1 3 4 2 6 5
RRLLRL 2 2 2 2 2

 */
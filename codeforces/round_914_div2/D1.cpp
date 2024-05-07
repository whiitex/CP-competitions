#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

#define f first
#define s second

const int MAXN = 1e5;

void solve() {
    int n; cin >> n;
    vi a(n); for (int &i: a) cin >> i;
    vi b(n); for (int &i: b) cin >> i;

    bool ok = true;
    for (int i=0; i<n; ++i) if (b[i] < a[i]) ok = false;

    if (!ok) {
        cout << "No" << '\n'; return;
    }

    vector<bool> vecok(n, false);

    // left
    for (int i=0; i<n; ++i) {
        if (vecok[i]) continue;
        if (a[i] == b[i]) {
            vecok[i] = true;
            continue;
        }

        bool flag = true;
        int j = i-1;
        for (; j >= 0; --j) {
            if (a[j] == b[i]) break;
            if (b[j] < b[i] or a[j] > b[i]) {
                flag = false;
                break;
            }
        }

        if (a[j] != b[i]) flag = false;
        vecok[i] = flag;
    }

    // right
    for (int i=n-1; i>=0; --i) {
        if (vecok[i]) continue;

        bool flag = true;
        int j = i+1;
        for (; j < n; ++j) {
            if (a[j] == b[i]) break;
            if (b[j] < b[i] or a[j] > b[i]) {
                flag = false;
                break;
            }
        }

        if (a[j] != b[i]) flag = false;
        vecok[i] = flag;
    }

    bool ans = true;
    for (bool i: vecok) ans &= i;

    cout << (ans ? "Yes" : "No") << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}

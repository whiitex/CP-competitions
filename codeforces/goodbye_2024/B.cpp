#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
    int n; cin >> n;
    vi l(n), r(n);
    for (int i=0; i<n; ++i) {
        cin >> l[i] >> r[i];
    }

    set<int> ok; for (int i=1; i<=2*n; ++i) ok.insert(i);
    unordered_map<int,int> freq;
    for (int i=0; i<n; ++i) {
        if (l[i] == r[i]) {
            ok.erase(l[i]);
            ++freq[l[i]];
        }
    }

    for (int i=0; i<n; ++i) {
        if (l[i] == r[i]) {
            if (freq[l[i]] == 1) cout << 1;
            else cout << 0;
        } else {
            auto it = ok.lower_bound(l[i]);

            if (it == ok.end()) cout << 0;
            else cout << (*it <= r[i] ? 1 : 0);
        }
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

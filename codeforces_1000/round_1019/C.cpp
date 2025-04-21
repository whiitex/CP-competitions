#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

void solve() {
    int n, k; cin >> n >> k;
    vi a(n); for (int &i: a) cin >> i;

    auto doit = [&]() -> bool {
        int LEQ = 0, GR = 0;
        set<array<int,4>> st;
        for (int i=0; i<n; ++i) {
            a[i] >= k ? ++LEQ : ++GR;
            st.insert({LEQ - GR, LEQ+GR, LEQ, GR});
        }

        int leq = 0, gr = 0;
        for (int i=0; i<n-2; ++i) {
            a[i] > k ? ++gr : ++leq;

            st.erase({leq - gr, leq+gr, leq, gr});

            if (gr <= leq) {
                if (a[i+1] <= k) return true;
                auto it = st.lower_bound({leq - gr, 0, 0});
                if (it == st.end()) continue;
                auto [diff, sm, l, g] = *it;

                if (sm != n and diff >= leq - gr) return true;
            }
        }

        return false;
    };

    bool one = doit();
    reverse(a.begin(), a.end());
    bool two = doit();

    int l = 0, g = 0, isx = -1;
    for (int i=0; i<n; ++i) {
        a[i] > k ? ++g : ++l;
        if (l >= g) { isx = i; break; }
    }

    l = 0, g = 0; int irx = -1;
    for (int i=n-1; i>=0; --i) {
        a[i] > k ? ++g : ++l;
        if (l >= g) { irx = i; break; }
    }

    bool tre = isx != -1 and irx != -1 and isx < irx - 1;

    if (one or two or tre) cout << "YES\n";
    else cout << "NO\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

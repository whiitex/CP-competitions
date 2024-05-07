#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> vec(n);
    for (int i=0; i<n; ++i) cin >> vec[i];

    if (k>2)
        cout << 0 << '\n';
    else if (k == 1) {
        ll m = LONG_LONG_MAX;
        for (int i=0; i<n; ++i) m = min(m, vec[i]);
        for (int i=0; i<n-1; ++i) {
            for (int j=i+1; j<n; j++) {
                m = min(m, abs(vec[i] - vec[j]));
            }
        }

        cout << m << '\n';
    } else {
        sort(vec.begin(), vec.end());

        ll m = LONG_LONG_MAX;
        for (int i=0; i<n; ++i) m = min(m, vec[i]);

        for (int i=0; i<n-1; ++i) {
            for (int j=i+1; j<n; j++) {
                ll nuovo = abs(vec[i] - vec[j]);

                m = min(nuovo, m);
                int l=0, r=n;
                while(l<r) {
                    int mid = l+r >> 1;
                    if (vec[mid] < nuovo)
                        l = mid+1;
                    else r = mid;
                }

                for (int i=max(l-2, 0); i< min((int)n,l+2); ++i) {
                    m = min(m, abs(nuovo- vec[i]));
                }
            }
        }

        cout << m << '\n';

    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

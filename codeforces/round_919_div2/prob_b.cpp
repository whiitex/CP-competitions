#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
const ll INF = 1e9;

void solve() {
    int n, k, x; cin >> n >> k >> x;
    vi vec;
    int sum = 0, el;
    for (int i=0; i<n; ++i) {
        cin >> el;
        sum += el;
        vec.push_back(el);
    }

    std::sort(vec.begin(), vec.end());
    vi pref(n); pref[0] = vec[0];
    for (int i=1; i<n; ++i) pref[i] = pref[i-1] + vec[i];

    int mx = -INF;
    for (int i=0; i<=k; ++i) {
        if (i >= n) mx = max (mx, 0);
        else {
            if (x >= n - i) mx = max(mx, -pref[n - 1 - i]);
            else {
                int a = pref[n - 1 - i - x]; // positive
                int b = pref[n - 1 - i];     // negative
                mx = max(mx, 2*a - b);
            }
        }
    }

    cout << mx << '\n';
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

#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
    int n, k, l; cin >> n >> k >> l;
    vi a(n); for (int &i: a) cin >> i;
    for (int &i: a) i *= 2; k *= 2; l *= 2;

    int time = a[0], x = k;
    for (int i=1; i<n and x < l; ++i) {
        if (a[i] <= x) {
            a[i] = min(x, a[i] + time);

        } else {
            a[i] = max(x, a[i] - time);

            int delta = (a[i] - x) / 2;
            if (delta > l-x) {
                x += l-x;
                time += l-x;
                break;
            }
            delta = min(delta, l-x);
            time += delta;
            a[i] -= delta;
        }

        x = a[i] + k;
    }

    cout << time + max(0ll, l-x) << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

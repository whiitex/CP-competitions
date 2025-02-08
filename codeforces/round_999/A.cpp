#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
    int n; cin >> n;
    vi a(n); for (int &i: a) cin >> i;

    for (int i=1; i<n; ++i) {
        if (a[i] % 2 == 0) {
            swap(a[0], a[i]);
            break;
        }
    }

    auto sim = [&] (int x=0) -> int {
        int ret = 0;
        for (int i: a) {
            x += i;
            if (x % 2 == 0) ++ret;
            while (x % 2 == 0) x >>= 1;
        }
        return ret;
    };

    cout << sim() << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

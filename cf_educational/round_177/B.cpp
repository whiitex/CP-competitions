#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
    int n, k, x; cin >> n >> k >> x;
    vi a(n); for (int &i: a) cin >> i;

    int sm = 0; for (int i: a) sm += i;
    if (sm * k < x) { cout << 0 << '\n'; return; }

    int l = n*k, tot = 0;
    while (tot + sm < x) {
        tot += sm;
        l -= n;
    }

    int i = n-1;
    while (tot < x) {
        tot += a[i--];
    }

    cout << l - (n-1 - i - 1) << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

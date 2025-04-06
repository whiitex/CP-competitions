#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
    int n, c, k; cin >> n >> c >> k;
    string s; cin >> s;

    vector<bool> cant_none((1 << c), false);
    int cur_mask = 0;
    vi cnt(c, 0);

    for (int i=0; i<k-1; ++i) {
        cur_mask |= (1 << (s[i] - 'A'));
        ++cnt[s[i] - 'A'];
    }
    for (int i=k-1; i<n; ++i) {
        ++cnt[s[i] - 'A'];
        cur_mask |= (1 << (s[i] - 'A'));
        cant_none[cur_mask] = true;

        --cnt[s[i-k+1] - 'A'];
        if (!cnt[s[i-k+1] - 'A']) cur_mask ^= (1 << (s[i-k+1] - 'A'));
    } cant_none[(1 << (s[n-1] - 'A'))] = true;

    int ans = c;
    for (int i=0; i< (1<<c); ++i) {
        if (cant_none[i]) {
            for (int bit=0; bit<c; ++bit) {
                cant_none[(i | (1 << bit))] = true;
            }
        } else ans = min(ans, c - __builtin_popcount(i));
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

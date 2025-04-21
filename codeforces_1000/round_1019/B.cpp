#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;

#define pb push_back

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vi a; for (char c: s) a.pb(c - '0');


    auto count = [] (vi a) -> int{
        int ans = a.size(), c = 0;
        for (int i=0; i<a.size(); ++i) {
            if (c != a[i]) {
                ++ans; c ^= 1;
                assert(c == a[i]);
            }
        } return ans;
    };

    int ans = count(a);

    vi b(a); reverse(b.begin(), b.end());
    ans = min(ans, count(b));

    {
        int i = 0; while (i < n and a[i] == a[0]) ++i;
        int j = i; while (j < n and a[j] == a[i]) ++j;
        int k = j; while (k < n and a[k] == a[j]) ++k;

        if (j < n) {
            vi c(a);
            reverse(c.begin()+i, c.begin()+k);
            ans = min(ans, count(c));
        }
    }

    {
        int i = 0; while (i < n and a[i] == a[0]) ++i;
        int j = i; while (j < n and a[j] == a[i]) ++j;

        if (i < n) {
            vi c(a);
            reverse(c.begin(), c.begin()+j);
            ans = min(ans, count(c));
        }
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

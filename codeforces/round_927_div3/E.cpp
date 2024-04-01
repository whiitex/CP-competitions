#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

#define pb push_back

void solve() {
    ll n, i=0, sum=0; cin >> n;
    string s; cin >> s;
    vi vec(n);
    for (char c: s) {
        vec[i] = c-'0';
        sum += vec[i];
        ++i;
    }

    ll rem = sum/10;
    vi ans;

    ans.pb(sum % 10);

    for (int i=n-1; i>=0; --i) {
        sum -= vec[i];
        ans.pb((sum + rem) % 10);
        rem = (sum + rem) / 10;
    }

    std::reverse(ans.begin(), ans.end());
    i = 0; while (ans[i] == 0) ++i;
    for (; i<=n; ++i) cout << ans[i];
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t; cin >> t;
    while (t--) {
        solve();
    }
}

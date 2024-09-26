#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

#define pb push_back

const int INF = 1e9;

void solve() {
    int n; cin >> n;
    vi vec(n); for (int &i: vec) cin >> i;
    set<int> st; for (int i: vec) st.insert(i);

    if (n == 1) {
        cout << 0 << '\n';
        return;
    }

    int lcm = vec[0];
    for (int i=1; i<n; ++i) {
        lcm = lcm * vec[i] / __gcd(lcm, vec[i]);
        if (lcm > INF) {
            cout << n << '\n';
            return;
        }
    }

    vi divisors(1);
    for (int i=1; i<INF; ++i) {
        if (lcm % i == 0) {
            divisors.pb(i);
            divisors.pb(lcm/i);
        }

        if (i * i > lcm) break; // O(sqrt(1e9))
    }

    int ans = 0;
    for (int div: divisors) { // O(sqrt3(1e9))

        int now_lcm = 1, count = 0;
        for (int num: vec) {
            if (div % num == 0) {
                now_lcm = now_lcm * num / __gcd(now_lcm, num);
                ++count;
            }
        }

        if (st.find(now_lcm) == st.end()) ans = max(ans, count);
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

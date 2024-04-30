#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;


void solve() {
    int n, k; cin >> n >> k;
    vi vec(n); for (int &i: vec) cin >> i;

    std::sort(vec.begin(), vec.end());

    int until = 1;
    for (int i=0; i<n-1; ++i) {
        if ((i+1) * (vec[i+1] - vec[i]) <= k) {
            k -= (i + 1) * (vec[i + 1] - vec[i]);
            ++until;
        }
        else break;
    }

    for (int i=0; i<until; ++i) vec[i] = vec[until-1];

    int rem = until;
    for (int i=0; i<until; ++i) {
        vec[i] += k/rem;
        k -= k/rem;
        --rem;
    }

    std::sort(vec.begin(), vec.end());
    int mn = vec[0];
    int count = 0;
    while (count < n and vec[count] == mn) ++count;
    int more = n - count;

    int ans = (n * mn) - n+1;
    ans += more;

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}

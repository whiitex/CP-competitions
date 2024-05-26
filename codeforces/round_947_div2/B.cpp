#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
    int n; cin >> n;
    vi vec(n); for (int &i: vec) cin >> i;

    std::sort(vec.begin(), vec.end());

    int ai = vec[0];
    int i=1;
    while (i < n and vec[i] % ai == 0) ++i;
    if (i == n) {
        cout << "Yes\n";
        return;
    }

    int aj = vec[i];
    ++i;

    while (i<n and (vec[i] % ai == 0 or vec[i] % aj == 0)) ++i;

    if (i == n) cout << "Yes\n";
    else cout << "No\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}

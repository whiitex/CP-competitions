#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
    int n, k; cin >> n >> k;
    vi vec(n); for (int &i: vec) cin >> i;

    sort(vec.begin(), vec.end());
    int prev = -9, window = 0, ans = -9, sum = 0;
    deque<int> dq;
    for (int i=0; i<n;) {
        int j=i+1;
        while (j < n and vec[j] == vec[i]) ++j;
        int tot = j-i;

        if (vec[i] > prev+1) {
            sum = tot;
            window = 1;
            dq.clear();
        } else if (window == k) {
            sum -= dq.front();
            dq.pop_front();
            sum += tot;
        } else {
            sum += tot;
            ++window;
        }

        dq.push_back(tot);
        prev = vec[i];
        ans = max(ans, sum);
        i = j;
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}

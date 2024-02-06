#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

void solve() {
    int n, k; cin >> n >> k;
    vi ans(n);
    int N = n, KK = k;

    int l=1, r=n;
    ans[0] = 1;
    ans[1] = n;
    n -= k;
    k -= 2;

    int j = 2, inc;
    while (k) {
        inc = (n + k+1) / (k+2);
        l += inc+1;
        n -= inc;
        --k;
        ans[j++] = l;

        inc = (n + k+1) / (k+2);
        r -= inc+1;
        n -= inc;
        --k;
        ans[j++] = r;
    }

    for (int i=j; i<N; ++i) {
        if (ans[i-KK] <= N/2+1)
            ans[i] = ans[i-KK] + 1;
        else ans[i] = ans[i-KK] - 1;
    }

    for(int i: ans)
        cout << i << ' ';
    cout << '\n';

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}

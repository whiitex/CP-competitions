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


/* no
 void solve() {
    int n, k; cin >> n >> k;
    vi ans(n);

    int KK = k;

    if (n == 2) {
        cout << "1 2\n";
        return;
    }

    if (n&1) { // odd
        int j = 0;

        if (KK >= n/2) {
            for (int i = 1; i <= n / 2 and k > 1; i += 2) {
                ans[j++] = (i == 1 ? 1 : i+1);
                ans[j++] = n + 1 - i;
                k -= 2;
            }

            if (k > 0) {
                int l = n / 2 + 1;
                int r = l + 1;
                ans[j++] = l;
                ans[j++] = r;
                --l;
                r += 2;
                k -= 2;
                while (k > 0) {
                    ans[j++] = l;
                    ans[j++] = r;
                    l -= 2;
                    r += 2;
                    k -= 2;
                }
            }
        } else {
            for (int i = 1; i <= n / 2 and k > 1; i += (n/KK)) {
                ans[j++] = (i == 1 ? 1 : i+1);
                ans[j++] = n + 1 - i;
                k -= 2;
            }
        }

        for (int i=j; i<n; ++i) {
            if (ans[i-KK] < n/2+1)
                ans[i] = ans[i-KK] + 1;
            else ans[i] = ans[i-KK] - 1;
        }
    } else {
        int j = 0;

        if (KK >= n/2) {
            for (int i = 1; i < n / 2 and k > 1; i += 2) {
                ans[j++] = i;
                ans[j++] = n + 1 - i;
                k -= 2;
            }

            if (k > 0) {
                int l = n / 2;
                int r = l + 1;
                ans[j++] = l;
                ans[j++] = r;

                l -= 2;
                r -= 2;
                k -= 2;

                while (k > 0) {
                    ans[j++] = l;
                    ans[j++] = r;
                    l -= 2;
                    r -= 2;
                    k -= 2;
                }
            }
        } else {
            for (int i = 1; i < n / 2 and k > 1; i += (n/KK)+1) {
                ans[j++] = i;
                ans[j++] = n + 1 - i;
                k -= 2;
            }
        }

        for (int i=j; i<n; ++i) {
            if (ans[i-KK] < n/2+1)
                ans[i] = ans[i-KK] + 1;
            else ans[i] = ans[i-KK] - 1;
        }
    }

    for(int i: ans)
        cout << i << ' ';
    cout << '\n';

}


 */

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

const ll PERM = 355687428096000;


void solve() {
    // init
    int n, k; cin >> n >> k;

    // solve
    if (n==1 and k==1) {
        cout << "YES" << '\n';
        cout << 0 << '\n';
    }
    else if (n==1 or k>n-1) cout << "NO" << '\n';
    else if (k==1) {
        cout << "YES" << '\n';
        if (n==2) {
            cout << 1 << '\n';
            cout << 1 << ' ' << 2;
        } else {
            cout << n << '\n';
            cout << 1 << ' ' << n << '\n';
            for (int i=1; i<n; ++i)
                cout << i << ' ' << i+1 << '\n';
        }
    } else {
        cout << "YES" << '\n';
        int pair = k - (k%2);
        int roads = (n-1 + n-1-(pair-2)) * (pair/2) /2;
        if (k%2 == 1) roads++;
        cout << roads << '\n';
        int source = 1, initial=n;
        for (int i=initial; i>source; --i)
            cout << i << ' ' << source << '\n';
        k -= 2;
        while (k>1) {
            ++source;
            --initial;
            for (int i=initial; i>source; --i)
                cout << i << ' ' << source << '\n';
            k-=2;
        }

        if (k == 1) {
            ++source;
            --initial;
            cout << initial << ' ' << source << '\n';
        }
    }

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t=1;
//    cin >> t;
    while (t--) {
        solve();
    }
}

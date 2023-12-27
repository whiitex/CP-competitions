#include <bits/stdc++.h>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "ArrayIndexOutOfBounds"
using namespace std;

#define ll long long

void solve() {
    string s; cin >> s;
    int n = s.length();
    vector<ll> vec(n);
    for (ll i = 0; i < n; ++i)
        vec[i] = s[i] - 'A';

    ll pows[5] {1, 10, 100, 1000, 10000};

    ll dp[n+1][5][2]; // position - highest value so far - changed
    memset(dp, INT32_MIN, sizeof(dp));

    // init

    for (int i=n; i>=0; --i)
        for (int prev=0; prev<5; ++prev)
            for (int k=0; k<2; ++k)
                dp[i][prev][k] = LONG_LONG_MIN;

    dp[n][0][0] = 0;

    // dp solving
    for (int i=n; i>0; --i) {
        for (int prev=0; prev<5; prev++) {
            for (int k=0; k<2; ++k) {
                for (int nw=0; nw<5; nw++) {

                    // if already changed -> don't change
                    if (k == 1 and nw != vec[i-1]) continue;

                    // change here
                    else {
                        int kk = (nw == vec[i-1] and k==0) ? 0 : 1;
                        int sign = (nw >= prev) ? 1 : -1;
                        dp[i-1][max(prev,nw)][kk] = max(dp[i-1][max(prev,nw)][kk], dp[i][prev][k] + sign*pows[nw]);
                    }

                }
            }
        }

    }

    ll best = LONG_LONG_MIN;
    for (int v=0; v<5; ++v)
        for (int h=0; h<2; ++h)
            best = max(best, dp[0][v][h]);

    cout << best << '\n';


}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
}


/* GREEDY SOLUTION
 * if (n == 1) {
        cout << 10000 << '\n';
        return;
    } else {
        ll sum = 0;
        ll high = 0;
        for (ll i=n-1; i>=0; --i) {
            if (vec[i]>=high)
                sum += (ll)pow(10, vec[i]);
            else sum -= (ll)pow(10, vec[i]);
            if (high < vec[i])
                high = vec[i];
        }

        vector<vector<ll>> left(n);
        left[0] = {0,0,0,0,0};
        for(ll i=1; i<n; ++i) {
            left[i] = {0,0,0,0,0};
            for (ll k=0; k<vec[i-1]; ++k)
                left[i][k] = 0;
            for (ll k=vec[i-1]; k<5; ++k)
                left[i][k] = left[i-1][k];
            ++left[i][vec[i-1]];
        }

        vector<ll> right(n);
        right[n-1] = 0;
        right[n-2] = vec[n-1];
        for (ll i = n-2; i>=0; --i) {
            right[i] = max(right[i+1], vec[i+1]);
        }

        vector<ll> update(n,LONG_LONG_MIN);
        for (ll i=0; i<n; ++i) {
            set<ll> st = {0,1,2,3,4};
            st.erase(vec[i]);
            for (ll v: st) {
                ll vecchio, nuovo;
                if (vec[i] < right[i])
                    vecchio = -(ll)pow(10,vec[i]);
                else vecchio = (ll)pow(10,vec[i]);
                if (v<right[i])
                    nuovo = -(ll)pow(10,v) - vecchio;
                else {
                    nuovo = (ll)pow(10,v) - vecchio;
                    for (ll k=0; k<5; ++k) {
                        if (k<v and k>=right[i] and k>=vec[i])
                            nuovo -= 2 * left[i][k] * (ll)pow(10,k);
                        else if (k>=v and k>=right[i] and k<vec[i])
                            nuovo += 2 * left[i][k] * (ll)pow(10,k);
                    }
                }
                update[i] = max(update[i], nuovo);
            }

        }

        ll best = max(update[0], update[1]);
        for (ll i=2; i<n; ++i)
            best = max(best, update[i]);
        cout << sum + best << '\n';
    }
 */

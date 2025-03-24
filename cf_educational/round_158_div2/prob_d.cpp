#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

const ll MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

class Node {
public:
    ll a;
    ll i;
    vector<Node*> children;
    Node(ll value, ll index) {
        a = value;
        i = index;
    }
};

void solve() {
    int n; cin >> n;
    vector<ll> input(n);
    for (int i=0; i<n; ++i)
        cin >> input[i];

    // value requested if chosen index is on the RIGHT / LEFT
    vector<pair<ll,ll>> worst(n);
    for(int i=0; i<n; ++i) {
        worst[i].first = input[i] + i;
        worst[i].second = input[i] + n-1 - i;
    }

    vector<ll> maxr(n), maxl(n);

    // max value for each position on right / left
    maxr[0] = input[0];
    for (int i=1; i<n; ++i)
        maxr[i] = max(maxr[i-1], worst[i-1].second);

    maxl[0] = input[n-1];
    for (int i=n-2; i>=0; --i)
        maxl[i] = max(maxl[i+1], worst[i+1].first);
    
    // dp for finding all required values and the minimum value among all
    vector<ll> dp(n);
    ll sol = LONG_LONG_MAX;
    for (int i=0; i<n; ++i) {
        dp[i] = max(maxl[i], maxr[i]);
        if (dp[i] < input[i])
            dp[i] = input[i];
        sol = min(sol, dp[i]);
    }

    cout << sol << '\n';

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}

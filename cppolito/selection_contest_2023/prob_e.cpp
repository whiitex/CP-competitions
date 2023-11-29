#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

class Node {
public:
    ll a;
    int i;
    vector<Node*> children;
    Node(ll value, int index) {
        a = value;
        i = index;
    }
};


bool check(ll arr[], ll k, ll n, ll t) {
    ll count = 0;
    for (int i=0; i<n-1; ++i) {
        if (arr[i+1] - arr[i] >= k)
            count += k;
        else count += arr[i+1] - arr[i];
    }
    count += k;
    return count >= t;
}

void solve() {

    ll n, t;
    cin >> n >> t;

    ll arr[n];
    for (int i=0; i<n; ++i) {
        cin >> arr[i];
    }

    ll l=1, r=1e18, mid;
    while (l<r) {
        mid = (l+r) >> 1;
        bool ck = check(arr, mid, n, t);
        if (ck)
            r = mid;
        else l = mid + 1;

    }
    cout << l << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

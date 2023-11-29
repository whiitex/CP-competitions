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

void solve() {
    ll n;
    cin >> n;

    pair<ll,ll> caves[n];
    for(int i=0; i<n; ++i) {
        ll len;
        cin >> len;
        ll max; cin >> max;
        ll temp;
        for (int j=1; j<len; ++j) {
            cin >> temp;
            if (temp - j > max) max = temp - j;
        }
        caves[i] = {max, len};
    }

    sort(caves, caves+n);

    ll res = 0;
    ll power = 0;
    for(pair<ll,ll> p: caves) {
        if (power <= p.first) {
            res += p.first - power + 1;
            power += p.first - power + 1;
        }
        power += p.second;
    }

    cout << res << '\n';
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

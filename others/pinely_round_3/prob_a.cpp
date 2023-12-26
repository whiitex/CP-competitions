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
    int n; cin >> n;
    vector<pair<int,int>> vec(n);
    bool d=false, u=false, r=false, l=false;
    for (int i=0; i<n; ++i) {
        cin >> vec[i].first >> vec[i].second;
        if (vec[i].first > 0) r = true;
        if (vec[i].first < 0) l = true;
        if (vec[i].second > 0) u = true;
        if (vec[i].second < 0) d = true;
    }

    if (!d or !u or !l or !r)
        cout << "YES\n";
    else cout << "NO\n";


}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
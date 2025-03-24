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
    vector<int> vec(n);
    for (int i=0; i<n; ++i)
        cin >> vec[i];

    if (n == 1)
        cout << vec[0]-1 << '\n';
    else {
        ll sol = vec[0]-1;
        for (int i=0; i<n-1; ++i) {
            if (vec[i] < vec[i+1])
                sol += vec[i+1] - vec[i];
        }
        cout << sol << '\n';
    }

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

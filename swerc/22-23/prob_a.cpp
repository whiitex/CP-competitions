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
    vector<int> vec(n+2);
    vec[0] = 0;
    for (int i=1; i<n+1; ++i)
        cin >> vec[i];
    vec[n+1] = 1440;

    int count = 0;
    for (int i=1; i<n+2; ++i) {
        if (vec[i] - vec[i-1] >= 240)
            count += 2;
        else if (vec[i] - vec[i-1] >= 120)
            count++;
    }

    if (count >= 2)
        cout << "YES" << '\n';
    else cout << "NO" << '\n';

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
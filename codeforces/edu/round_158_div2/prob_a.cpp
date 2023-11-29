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

bool contains(vector<int> v, int i) {
    for (int val:v)
        if (val == i)
            return true;
    return false;
}

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> arr(n+1, 0);
    for (int i=1; i<n+1; ++i)
        cin >> arr[i];

    int min = 0;
    for (int i=0; i<n; ++i)
        if (arr[i+1] - arr[i] > min)
            min = arr[i+1] - arr[i];
    if (2 * (x - arr[n]) > min)
        min = 2*(x - arr[n]);
    cout << min << '\n';
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
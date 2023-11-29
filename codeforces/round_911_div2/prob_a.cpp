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
    string s; cin >> s;

    int i=0;
    while (s[i] == '#') ++i;

    int two=0, one=0, three=0, count;
    while (i<n) {
        count = 0;
        while (s[i] == '.') {
            ++count; ++i;
        }
        while (s[i] == '#')
            ++i;
        if (count == 1)
            ++one;
        else if (count == 2)
            ++two;
        else ++three;
    }

    if (three > 0)
        cout << 2 << '\n';
    else cout << two*2 + one << '\n';




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
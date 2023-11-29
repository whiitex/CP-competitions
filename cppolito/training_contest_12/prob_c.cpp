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
    ll n, m;
    cin >> n >> m;

    int fives_m = 0;
    ll copy = m;
    while (copy / 5 >= 1) {
        copy /= 5;
        ++fives_m;
    }
    
    int twos_m = 0;
    copy = m;
    while (copy / 2 >= 1) {
        copy /= 2;
        ++twos_m;
    }

    int copy_n = n;
    while (copy_n % 10 == 0)
        copy_n /= 10;

    int fives_n = 0;
    copy = copy_n;
    while (copy % 5 == 0) {
        copy /= 5;
        ++fives_n;
    }

    int twos_n = 0;
    copy = copy_n;
    while (copy % 2 == 0) {
        copy /= 2;
        ++twos_n;
    }

    ll prod = 1;

    // complete n fives/twos
    if (fives_n == 0) {
        if (fives_m > twos_n)
            prod = pow(5, twos_n);
        else prod = pow(5,fives_m);

    } else if (twos_n == 0) {
        if (twos_m > fives_n)
            prod = pow(2, fives_n);
        else prod = pow(2, twos_m);
    }

    // add tens
    while (prod * 10 < m)
        prod *= 10;

    // getting mulptiples
    if (prod*2 <= m)
        prod *= m/prod;

    if ((n*prod)%10 == 0)
        cout << n*prod << '\n';
    else cout << n*m << '\n';
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

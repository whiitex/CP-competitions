#include <bits/stdc++.h>
#define ll long long

using namespace std;

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

ll power(ll b, ll exp) {
    while (exp--)
        b *= 2;
    return b;
}

void solve(){
    ll n, q;
    cin >> n >> q;

    // init
    ll a[n], x[q], powers[31];
    for (ll i=0; i<n; i++)
        cin >> a[i];
    for (ll i=0; i<q; i++)
        cin >> x[i];

    // powers
    powers[0] = 1;
    for (ll i=1; i<31; i++)
        powers[i] = power(2, i-1);

    set<ll> logs[31];
    for (ll i=1; i<n; i++) {
        int pow = 30;
        while (a[i] % powers[pow] != 0)
            pow --;
        if (pow != 0) logs[pow].insert(i);
    }


    // solve
    ll my_x;
    for (ll i=0; i<q; i++) {
        my_x = x[i];
        for (ll j: logs[my_x]) {
            a[j] += powers[my_x-1];
            ll pow = my_x;
            while (a[j] % powers[pow] != 0)
                pow --;
            if (pow != 0) logs[pow].insert(j);
        }
        logs[my_x].clear();
    }




    // final print
    for (ll i=0; i<n; i++)
        cout << a[i] << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
}

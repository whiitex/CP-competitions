#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;


void solve() {
    ll n, P, l, t; cin >> n >> P >> l >> t;

    ll tasks = (n+6) / 7, bonus=0;
    if (tasks % 2) {
        tasks--;
        bonus=1;
    }

    ll work = 0;
    if (tasks*t + l*tasks/2 >= P) {
        work = (P + 2*t + l -1) / (2*t + l);
        cout << n-work << '\n';
        return;
    } else {
        work += tasks / 2;
        P -= tasks*t + l*tasks/2;
        if (bonus) {
            ++work;
            P -= l+t;
        }

        if (P<0) {
            cout << n-work << '\n';
            return;
        }
    }

    if (P>0)
        work += (P+l-1)/l;

    cout << n-work << '\n';
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

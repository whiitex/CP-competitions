#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

const ll MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    ll arr[n];
    for (ll i=0; i<n; ++i)
        cin >> arr[i];

    ll res = 1;
    ll gar = 0;
    while (arr[gar] == 0 and gar<n)
        ++gar;

    for (ll i=gar; i<n; ++i) {

        ll index = i+1;
        while (arr[index] == 0 and index < n)
            index++;

        if (index != n)
            res *= (index-i);

        i = index - 1;
    }

    bool zeros = true;
    for (int i=0; i<n; ++i) {
        if (arr[i] == 1) {
            zeros = false;
            break;
        }
    }
    if (zeros)
        cout << 0 << '\n';
    else cout << res << '\n';
}

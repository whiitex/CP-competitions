#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve() {
    int n; cin >> n;

    vector<int> vec(n);
    map<int, bool> m;
    int high = INT32_MIN;
    for (int i=0; i<n; ++i) {
        cin >> vec[i];
        m.insert({vec[i], true});
        high = max(high, vec[i]);
    }

    if (n == 1)
        cout << 1 << '\n';
    else if (n == 2)
        cout << 3 << '\n';
    else {
        int x = high - vec[0];
        for (int i = 1; i < n; ++i)
            x = __gcd(x, high - vec[i]);

        bool increment = true;
        for (int i=1; i<n; ++i) {
            if (m.find(high- i*x) == m.end()) {
                vec.push_back(high- i*x);
                increment = false;
                break;
            }
        }

        if (increment) {
            high += x;
            vec.push_back(high);
        }

        ll sol = 0;
        for (int el: vec) {
            sol += (ll)((high - el) / x);
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

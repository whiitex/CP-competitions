#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;


void solve(){

    // input
    int n, k, b = 0;
    string s;
    cin >> n >> k; cin >> s;
    for (int i=0; i<n; ++i)
        if (s[i] == 'B') b++;

    if (b == k) cout << 0 << '\n';
    else if (b < k) {
        int i=0, a=0;
        while (a != k-b) {
            if (s[i] == 'A') ++a;
            ++i;
        }
        cout << 1 << '\n';
        cout << i << " B" << '\n';
    } else {
        int i=0, a=0;
        while (a != b-k) {
            if (s[i] == 'B') ++a;
            ++i;
        }
        cout << 1 << '\n';
        cout << i << " A" << '\n';
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


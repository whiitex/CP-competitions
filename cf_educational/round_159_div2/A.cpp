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
    string s; cin >> s;

    int tot[2] = {0,0};
    tot[s[n-1]-'0']++;
    bool possible = false;
    for (int i=0; i<n-1; ++i) {
        tot[s[i]-'0']++;
        if (s[i] != s[i+1]) possible = true;
    }

    if (tot[0] > tot[1] or possible)
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
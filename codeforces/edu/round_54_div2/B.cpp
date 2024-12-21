#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef vector<int> vi;

void solve() {
    int n; cin >> n;

    if (n % 2 == 0) { cout << n/2 << '\n'; return;}

    vi sieve(1e6), primes;
    for (int i=2; i<(int)1e6; ++i) {
        if (!sieve[i]) for (int j=2*i; j<(int)1e6; j+=i) sieve[j] = 1;
        if (!sieve[i]) primes.push_back(i);
    }

    for (int i: primes) {
        if (n % i == 0) {
            cout << ((n-i) / 2) + 1 << endl;
            return;
        }
    }

    cout << 1 << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; //cin >> t;
    while (t--) solve();
}

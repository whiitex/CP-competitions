#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;

#define f first
#define s second

const int MAXN = 1e7+1;
vector<int> prime(MAXN, 0);

void solve() {
    int n; cin >> n;
    vi vec(n); for (int &i: vec) cin >> i;

    map<int,int> primes;
    int count = 0;
    for (int a: vec) {
        while (a > 1) {
            ++count;
            primes[prime[a]]++;
            a /= prime[a];
        }
    }

    int ans = 0;
    for (pii p: primes) {
        int c = p.s;
        if (c & 1) --c;

        ans += c/2;
        count -= c;
    }

    ans += count / 3;
    cout << ans << '\n';

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);


    prime[0] = prime[1] = 1;
    for (int i = 2; i <= MAXN; i++) {
        if (!prime[i]) {
            prime[i] = i;
            for (int j = i*2; j<MAXN; j+=i)
                if (!prime[j]) prime[j] = i;
        }
    }

    int t; cin >> t;
    while (t--) solve();
}

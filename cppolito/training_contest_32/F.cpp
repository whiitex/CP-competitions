#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

#define pb push_back
#define f first
#define s second

const int MAXN = 2e5 + 5;
const int MOD = 998244353;
const int INF = 1e18;


vector<int> fact(MAXN, 1);

int powerlogn(int b, int exp) {
    int mul = b % MOD;
    int ans = 1;
    while (exp) {
        if (exp & 1) ans = (ans * mul) % MOD;
        mul = (1ll * mul * mul) % MOD;
        exp /= 2;
    }
    return ans;
}

int binomial(int a, int b) {
    int ans = 1, A=a;
    while (A > b) {
        ans = (ans * A) % MOD; --A;
    }
    return (ans * powerlogn(fact[a-b], MOD-2)) % MOD;
}


int dist(int a, int b) {
    assert(a > b);
    int ans = 0;
    for (int i=40; i>=0 and b != a; --i) {
        int num = 1ll << i;
        if (b + num <= a)
            b += num, ++ans;
    }
    return ans;
}

void solve() {
    int n, k; cin >> n >> k;
    vi b(n+1); for (int i=1; i<=n; ++i) cin >> b[i];

    vi a(n+1); // for (int i=1; i<=n; i+=2) a[i] = b[i];
    for (int bit=0; 1<<bit <= n; ++bit) {
        for (int add=0; ; ++add) {
            int pos = (1 << bit) + (add << (bit + 1));
            if (pos > n) break;

            int num = b[pos];

            for (int i= pos+1 - (1<<bit); i<pos; ++i) {
                int mul = binomial(k-1 + dist(pos, i), max(dist(pos, i), k-1));
                int sub = (mul * a[i]) % MOD;
                num = (num + MOD - sub) % MOD;
               }

            a[pos] = num % MOD;
        }
    }

    for (int i=1; i<=n; ++i) cout << a[i] << ' '; cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i=2; i<MAXN; ++i) {
        fact[i] = (fact[i-1] * i) % MOD;
    }

    int t = 1; cin >> t;
    while (t--) solve();
}

#include <bits/stdc++.h>

using namespace std;
#define int long long

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

#define f first
#define s second

ll MOD;
const ll INF = 1e18;

int powerlogn(int b, int exp, int mod) {
    int mul = b;
    int ans = 1;
    while (exp) {
        if (exp & 1) ans = (ans * mul) % mod;
        mul = (mul*mul) % mod;
        exp >>= 1;
    }
    return ans;
}

int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

void solve() {
    int n, m; cin >> n >> m >> MOD;
    vi l(n+1), s(n+1);
    vector<vi> adj(n+1, vi(0));
    for (int i=1; i<=n; ++i) cin >> l[i];
    for (int i=1; i<=n; ++i) cin >> s[i];
    for (int i=0; i<m; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vi ans(n+1, INF);
    set<pii> pq;

    int ph = phi(MOD);


    // init
    pq.emplace(0, 1);
    ans[1] = 0;

    while (!pq.empty()) {
        auto pp = *pq.begin();
        int step = pp.f;
        int plat = pp.s;
        pq.erase(pp);

        for (int ch: adj[plat]) {
            int num = (l[plat] + s[plat] * (step%MOD) - l[ch] - s[ch] * (step%MOD));
            num %= MOD;
            if (num < 0) num += MOD;
            int den = (s[ch] - s[plat] + MOD) % MOD;

            int gcd = __gcd(den, MOD);
            if (num % gcd != 0) continue;

            num /= gcd;
            den /= gcd;
            int mod = MOD / gcd;
            den = powerlogn(den, ph-1, mod);
            int toadd = (num * den) % mod;


            int nextstep = step + toadd + 1;
            if (nextstep < ans[ch]) {
                pq.erase({ans[ch],ch}); // VERY IMPORTANT
                pq.emplace(nextstep, ch);
                ans[ch] = nextstep;
            }

        }
    }

    if (ans[n] == INF) ans[n] = -1;
    cout << ans[n] << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}

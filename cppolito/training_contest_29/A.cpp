#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

#define f first
#define s second

const int MAXN = 1e5 + 5;
vi fp(MAXN);

void solve() {
    int n, k; cin >> n >> k;
    vi vec(n); for (int &i: vec) cin >> i;

    unordered_map<int, int> mp;
    int ans = 0;
    for (int v: vec) {
        unordered_map<int, int> factors;
        while (v > 1) {
            ++factors[fp[v]];
            v /= fp[v];
        }

        int num = 1, find = 1;
        bool ok = true;
        for (pii mul: factors) {
            num *= pow(mul.f, (mul.s % k));
            ld a = pow(mul.f, (k - (mul.s % k)) % k);
            if (a > MAXN-5) {
                ok = false;
                break;
            } find *= a;
        }

        if (ok and find < MAXN) {
            ans += mp[find];
            ++mp[num];
        }
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i=2; i<MAXN; ++i) if (!fp[i]) {
        for (int j=i; j<MAXN; j += (i == 2 ? i : 2*i))
            fp[j] = i;
    }

    int t = 1; // cin >> t;
    while (t--) solve();
}

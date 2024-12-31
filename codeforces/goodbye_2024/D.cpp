#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

#define pb push_back
#define st first
#define nd second

const int MOD = 998244353;

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

int inv(int v) {
    return powerlogn(v, MOD-2) % MOD;
}


void solve() {
    int n, q; cin >> n >> q;
    vpii a(n), b(n);
    for (int i=0; i<n; ++i) { cin >> a[i].st; a[i].nd = i+1; }
    for (int i=0; i<n; ++i) { cin >> b[i].st; b[i].nd = i+1; }

    vpii sa(a), sb(b);
    sort(sa.begin(), sa.end());
    sort(sb.begin(), sb.end());

    unordered_map<int,int> vala, valb;
    unordered_map<int,int> posa, posb;
    for (int i=0; i<n; ++i) {
        vala[sa[i].nd] = sa[i].st;
        valb[sb[i].nd] = sb[i].st;
        posa[i] = sa[i].st;
        posb[i] = sb[i].st;
    }

    int ans = 1;
    for (int i=0; i<n; ++i) {
        ans *= min(sa[i].st, sb[i].st);
        ans %= MOD;
    } cout << ans << ' ';

    while (q--) {
        int o, x; cin >> o >> x;

        if (o == 1) { // increase a_x
            int oldval = vala[x];
            int l=0, r=n-1;
            while (l < r) {
                int m = l+r+1 >> 1;
                if (sa[m].st > oldval) r = m-1;
                else l = m;
            } int newpos = l;

            ans = (ans * inv(min(posa[newpos], posb[newpos]))) % MOD;
            ++posa[newpos]; ++sa[newpos].st; ++vala[x]; // update
            ans = (ans * min(posa[newpos], posb[newpos])) % MOD;
            cout << ans << ' ';
        } else { // increase b_x
            int oldval = valb[x];
            int l=0, r=n-1;
            while (l < r) {
                int m = l+r+1 >> 1;
                if (sb[m].st > oldval) r = m-1;
                else l = m;
            } int newpos = l;

            ans = (ans * inv(min(posa[newpos], posb[newpos]))) % MOD;
            ++posb[newpos]; ++sb[newpos].st; ++valb[x]; // update
            ans = (ans * min(posa[newpos], posb[newpos])) % MOD;
            cout << ans << ' ';
        }
    } cout << '\n';

}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) solve();
}
